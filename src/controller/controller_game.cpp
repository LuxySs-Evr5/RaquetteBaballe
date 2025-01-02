/**
 * @file controller_game.cpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Class that manage the current game
 */

#include "controller_game.hpp"
#include "level_manager/level_manager.hpp"

#include <allegro5/display.h>
#include <allegro5/keycodes.h>
#include <allegro5/timer.h>
#include <memory>
#include <vector>

ControllerGame::ControllerGame()
    : gameBoard_{make_shared<GameBoard>()},
      displayGame_(DisplayGame(gameBoard_)) {
    setupAllegro();
    startingGame();
}

ControllerGame::~ControllerGame() {
    if (timer_) {
        al_destroy_timer(timer_);
    }
    if (queue_) {
        al_destroy_event_queue(queue_);
    }
}

void ControllerGame::process() {
    while (!done_) {

        al_wait_for_event(queue_, nullptr);

        while (al_get_next_event(queue_, &event_)) { // get the next event
            checkEventType();
        }

        if (draw_) {
            drawGame();
        }
    }
}

void ControllerGame::drawGame() {
    displayGame_.draw(); // draw the pieces
    draw_ = false;       // no more need to draw
}

void ControllerGame::checkWinOrLose() {
    if (gameBoard_->getNumBricks() == 0) {
        // if the player has won
        al_stop_timer(timer_);
        displayGame_.gameWin();
        gameBoard_->saveBestScore();
        levelManager_.nextLevel();
        waitKeyToRestart();
        loadLevel();
    } else if (gameBoard_->getLife() == 0) {
        // if the player has lost
        al_stop_timer(timer_);
        displayGame_.gameOver();
        gameBoard_->saveBestScore();
        waitKeyToRestart();
        loadLevel();
    }
}

void ControllerGame::checkEventType() {
    if (event_.type
        == ALLEGRO_EVENT_DISPLAY_CLOSE) { // if the display will be closed
        done_ = true;
    }

    if (event_.type == ALLEGRO_EVENT_TIMER) {
        handleTick();
    }

    if (event_.type == ALLEGRO_EVENT_KEY_DOWN) {
        key_.set(event_.keyboard.keycode, true); // set the key pressed to true

        if (key_[ALLEGRO_KEY_Q]) {
            done_ = true;
        }
        if (key_[ALLEGRO_KEY_R]) {
            gameBoard_->resetBestScore();
        }
        if (key_[ALLEGRO_KEY_LEFT]) {
            al_stop_timer(timer_);
            levelManager_.previousLevel();
            loadLevel();
        }
        if (key_[ALLEGRO_KEY_RIGHT]) {
            al_stop_timer(timer_);
            levelManager_.nextLevel();
            loadLevel();
        }
        if (key_[ALLEGRO_KEY_A]) {
            al_stop_timer(timer_);
            loadLevel(); // restart the level
        }
        if (key_[ALLEGRO_KEY_SPACE]) {
            gameBoard_->shootLazerOrReleaseBall();
        }
    }

    if (event_.type == ALLEGRO_EVENT_KEY_UP) {
        key_.reset(
            event_.keyboard
                .keycode); // set the key that is no longer pressed to false
    }
}

void ControllerGame::waitKeyToRestart() {

    while (!(event_.type
             == ALLEGRO_EVENT_KEY_DOWN)) { // wait for a key to be pressed
        al_get_next_event(queue_, &event_);
        if (event_.type
            == ALLEGRO_EVENT_DISPLAY_CLOSE) { // if the display is closed
            done_ = true;
            break;
        }
        al_rest(0.001); // wait a little bit to not use 100% of the CPU
    }
}

void ControllerGame::loadLevel() {
    // Clear all the pieces of the game board
    gameBoard_->clear();

    // Reset the data of the game board
    gameBoard_->resetLifeCounter();
    gameBoard_->resetScore();

    // Load the level
    vector<shared_ptr<AbstractBrick>>
        copyBricks; // a copy of the bricks of the level to
                    // avoid modifying the original bricks
    for (const auto &brick : levelManager_.getBricks()) {
        copyBricks.emplace_back(brick->clone());
    }

    shared_ptr<Racket> racketCopy =
        make_shared<Racket>(*levelManager_.getRacket());

    // Set the pieces in the game board
    gameBoard_->setBorders(levelManager_.getBorders());
    gameBoard_->setRacket(racketCopy);
    gameBoard_->setBricks(copyBricks);

    // Start the timer
    al_start_timer(timer_);
}

void ControllerGame::setupAllegro() {
    if (!al_init()) { // initialize allegro
        cerr << "Failed to initialize Allegro" << endl;
        exit(1);
    }

    if (!al_install_keyboard()) {
        cerr << "Failed to install the keyboard" << endl;
        exit(1);
    }

    if (!al_install_mouse()) {
        cerr << "Failed to install the mouse" << endl;
        exit(1);
    }

    timer_ = al_create_timer(1.0 / UPS);
    if (!timer_) {
        cerr << "Failed to create timer" << endl;
        exit(1);
    }

    queue_ = al_create_event_queue();
    if (!queue_) {
        cerr << "Failed to create queue" << endl;
        exit(1);
    }

    al_register_event_source(
        queue_,
        al_get_display_event_source(
            displayGame_.getDisplay())); // register the display event source
    al_register_event_source(
        queue_,
        al_get_keyboard_event_source()); // register the keyboard event source
    al_register_event_source(
        queue_, al_get_mouse_event_source()); // register the mouse event source
    al_register_event_source(
        queue_,
        al_get_timer_event_source(timer_)); // register the timer event source
}

void ControllerGame::handleTick() {
    checkWinOrLose();

    al_get_mouse_state(&mouseState_);
    gameBoard_->setRacketAtX(
        static_cast<double>(mouseState_.x)); // move the racket with the mouse

    gameBoard_->update(1.0 / UPS);

    if (numberOfTick >= UPS / FPS) {
        draw_ = true; // draw the game (125 FPS)
        numberOfTick = 0;
    } else {
        numberOfTick++;
    }
}

void ControllerGame::startingGame() {
    displayGame_.gameLaunch();
    waitKeyToRestart();
    loadLevel();
}