/**
 * @file controller_game.cpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Class that manage the current game
 */

#include "controller_game.hpp"
#include "levels/levels.hpp"
#include "../model/brick/gold_brick.hpp"

#include <allegro5/display.h>
#include <allegro5/timer.h>
#include <memory>
#include <vector>

// ### Constructor ###
ControllerGame::ControllerGame()
    : gameBoard_{make_shared<GameBoard>()}, levels_(make_shared<Levels>()), displayGame_(make_shared<DisplayGame>(gameBoard_)) {
    setupAllegro();
    loadLevel();
}

// ### Destructor ###
ControllerGame::~ControllerGame() {
    if (timer_) {
        al_destroy_timer(timer_);
    }
    if (queue_) {
        al_destroy_event_queue(queue_);
    }
}

// ### Public methods ###
void ControllerGame::process() {
    while (!done_) {

        currentTime_ = al_get_time();
        double deltaTime = currentTime_ - lastTime_; // Time between two ticks
        lastTime_ = currentTime_;                    // Update the last time

        al_get_mouse_state(&mouseState_); // get the mouse state

        gameBoard_->setRacketAtX(static_cast<double>(
            mouseState_.x)); // move the racket with the mouse

        gameBoard_->update(deltaTime); // update the game board

        checkWinOrLose(); // check if the game is won or lost

        al_wait_for_event(queue_, nullptr);

        while (al_get_next_event(queue_, &event_)) { // get the next event
            checkEventType();
        }

        if (draw_) { // if the timer has ticked we draw the game
            drawGame();
        }
    }
}

// ### Private methods ###

void ControllerGame::drawGame() {
    displayGame_->draw(); // draw the pieces
    draw_ = false;        // no more need to draw
}

void ControllerGame::checkWinOrLose() {
    if (gameBoard_->getNumBricks() == 0) {
        // if the player has won
        al_stop_timer(timer_);
        displayGame_->gameWin();
        gameBoard_->saveRecordScore();
        levels_->nextLevel();
        waitKeyToRestart();
        loadLevel();
    } else if (gameBoard_->getLife() == 0) {
        // if the player has lost
        al_stop_timer(timer_);
        displayGame_->gameOver();
        gameBoard_->saveRecordScore();
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
        draw_ = true;
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
            levels_->previousLevel();
            loadLevel();
        }
        if (key_[ALLEGRO_KEY_RIGHT]) {
            al_stop_timer(timer_);
            levels_->nextLevel();
            loadLevel();
        }
        if (key_[ALLEGRO_KEY_A]) {
            al_stop_timer(timer_);
            loadLevel(); // restart the level
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
        al_rest(0.01); // wait a little bit to not use all the CPU
    }
}

void ControllerGame::loadLevel() {
    // Clear all the pieces of the game board
    gameBoard_->clear();

    // Reset the data of the game board
    gameBoard_->readBestScore();
    gameBoard_->resetLifeCounter();
    gameBoard_->resetScore();

    // Create the racket, the ball, the bricks and the borders
    const shared_ptr<Racket> &racket =
        make_shared<Racket>(levels_->getRacket());

    const shared_ptr<Ball> &ball = make_shared<Ball>(levels_->getBall());

    vector<shared_ptr<Brick>> bricks;
    for (const Brick &brick : levels_->getBricks()) {
        if (brick.getColor() == Color::gold) {
            bricks.emplace_back(make_shared<GoldBrick>(brick));
        } else {
            bricks.emplace_back(make_shared<Brick>(brick));
        }
    }

    vector<shared_ptr<Border>> borders;
    for (const Border &border : levels_->getBorders()) {
        borders.emplace_back(make_shared<Border>(border));
    }

    // Set the pieces in the game board
    gameBoard_->setBorders(borders);
    gameBoard_->setRacket(racket);
    gameBoard_->setBricks(bricks);
    gameBoard_->setBall(ball);

    // Start the timer
    al_start_timer(timer_);
    lastTime_ = al_get_time(); // get the time at the beginning of the game
}

void ControllerGame::setupAllegro() {
    if (!al_init()) { // initialize allegro
        cerr << "Failed to initialize Allegro" << endl;
        exit(-1);
    }

    if (!al_install_keyboard()) {
        cerr << "Failed to install the keyboard" << endl;
        exit(-1);
    }

    if (!al_install_mouse()) {
        cerr << "Failed to install the mouse" << endl;
        exit(-1);
    }

    timer_ = al_create_timer(1.0 / 360);
    if (!timer_) {
        cerr << "Failed to create timer" << endl;
        exit(-1);
    }

    queue_ = al_create_event_queue();
    if (!queue_) {
        cerr << "Failed to create queue" << endl;
        exit(-1);
    }

    al_register_event_source(
        queue_,
        al_get_display_event_source(
            displayGame_->getDisplay())); // register the display event source
    al_register_event_source(
        queue_,
        al_get_keyboard_event_source()); // register the keyboard event source
    al_register_event_source(
        queue_, al_get_mouse_event_source()); // register the mouse event source
    al_register_event_source(
        queue_,
        al_get_timer_event_source(timer_)); // register the timer event source
}
