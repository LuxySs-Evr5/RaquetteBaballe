/**
 * @file controller_game.cpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Class that manage the current game
 */

#include "controller_game.hpp"
#include "../global_variables.hpp"
#include "levels/levels.hpp"

// TODO : Arrêter toutes les ressoucrces quand y a le message de game over ou de
// win (autres affichages allegro et le backend)
// TODO : Décider si quand on ferme le jeu, ferme la fenêtre , on save le score
// avant de quiter

// ### Constructor ###
ControllerGame::ControllerGame()
    : gameBoard_{make_shared<GameBoard>()}, levels_(make_shared<Levels>()) {
    displayGame_ = make_shared<DisplayGame>(gameBoard_);

    setupAllegro();

    loadLevel(); // at the start of the game we start a level // TODO: check if
                 // good
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
        al_stop_timer(timer_);
        displayGame_->gameWin();
        gameBoard_->saveRecordScore();
        levels_->levelUp();
        waitKeyToRestart();
        loadLevel();
    } else if (gameBoard_->getLife() == 0) {
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
        if (key_[ALLEGRO_KEY_SPACE]) {
            // shootLazer(); TODO : shoot lazer when bonus
        }
        if (key_[ALLEGRO_KEY_LEFT]) {
            al_stop_timer(timer_);
            levels_->levelDown();
            loadLevel();
        }
        if (key_[ALLEGRO_KEY_RIGHT]) {
            al_stop_timer(timer_);
            levels_->levelUp();
            loadLevel();
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
    }
}

void ControllerGame::loadLevel() {
    gameBoard_->clear();

    // TODO: verify if it's the right way to do that
    vector<shared_ptr<Ball>> ball;
    ball.push_back(make_shared<Ball>(levels_->getBall()));
    vector<shared_ptr<Racket>> racket;
    racket.push_back(make_shared<Racket>(levels_->getRacket()));

    gameBoard_->setBorders(levels_->getBorders());
    gameBoard_->setRacket(racket);
    gameBoard_->setBricks(levels_->getBricks());
    gameBoard_->setBalls(ball);
    gameBoard_->readBestScore(); // TODO: maybe change name of the function
    gameBoard_->resetLifeCounter();
    gameBoard_->resetScore();
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

    timer_ =
        al_create_timer(1.0 / 360); // TODO: check the FPS we want for allegro
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
