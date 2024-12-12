/**
 * @file controller_game.cpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Class that manage the current game
 */

#include "controller_game.hpp"
#include "../global_variables.hpp"

#include <allegro5/allegro.h>

#include <allegro5/timer.h>
#include <iostream>
#include <thread>

using namespace std;

// TODO : Arrêter toutes les ressoucrces quand y a le message de game over ou de win (autres affichages allegro et le backend) 

constexpr std::chrono::duration<double> SLEEP_TIME(0.001);

// ### Constructor ###
ControllerGame::ControllerGame() : gameBoard_{make_shared<GameBoard>()} {

    displayGame_ = make_shared<DisplayGame>(gameBoard_);

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

    timer_ = al_create_timer(1.0 / 144); // TODO: check the FPS we want for allegro
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

// ### Destructor ###
ControllerGame::~ControllerGame() {}

// ### Public methods ###
void ControllerGame::process() {
    al_start_timer(timer_);
    using clock = std::chrono::high_resolution_clock;
    using time_point = std::chrono::time_point<clock>;
    using duration = std::chrono::duration<double>;

    time_point t_last_update =
        clock::now() - std::chrono::duration_cast<clock::duration>(SLEEP_TIME);

    while (!done_) {

        checkLife(); // check if the player has lifes // TODO : check if it's the right place to do that

        if (gameBoard_->getNbBricks() == 0) { // if there is no more bricks // TODO: not working
            win_ = true; 
        }

        time_point t_now = clock::now();

        duration delta_time = t_now - t_last_update;

        t_last_update = t_now;

        gameBoard_->update(delta_time.count());

        // Gestion du temps
        std::cout << "delta time= " << delta_time.count() << std::endl;
        std::this_thread::sleep_for(std::chrono::duration<double>(SLEEP_TIME));

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
    al_start_timer(timer_);
    draw_ = false;

    if (isGaming_ == true) { // if the game is running

        al_get_mouse_state(&mouseState_); // get the mouse state

        // check if the mouse is in the window
        if (mouseState_.x < 0) {
            mouseState_.x = 0;
        } else if (mouseState_.x > static_cast<int>(SCREEN_WIDTH)) {
            mouseState_.x = static_cast<int>(SCREEN_WIDTH);
        }

        gameBoard_->setRacketAtX(static_cast<double>(
            mouseState_.x)); // move the racket with the mouse

        displayGame_->draw(); // draw the pieces
    }

    else if (isGaming_ == false) { // the game is over because no more lifes
        gameBoard_->saveCurrentScore();
        displayGame_->gameOver(); // display the game over screen
        waitKeyToRestart();
    }

    else if (win_ == true) {     // the game is won
        displayGame_->gameWin(); // display the game win screen
        waitKeyToRestart();
        // TODO: launch a new level
    }
}

void ControllerGame::checkLife() {
    if (gameBoard_->getLife() == 0) {
        isGaming_ = false;
    }   
}

// ### Private methods ###

void ControllerGame::checkEventType() {
    if (event_.type
        == ALLEGRO_EVENT_DISPLAY_CLOSE) { // if the display is closed
        done_ = true;
    }

    else if (event_.type == ALLEGRO_EVENT_TIMER) {
        al_stop_timer(timer_);
        draw_ = true;

        if (key_[ALLEGRO_KEY_SPACE]) {
            // shootLazer(); TODO : shoot lazer when bonus
        }
    }

    else if (event_.type == ALLEGRO_EVENT_KEY_DOWN) {
        key_.set(event_.keyboard.keycode, true); // set the key pressed to true
    }

    else if (event_.type == ALLEGRO_EVENT_KEY_UP) {
        key_.reset(
            event_.keyboard
                .keycode); // set the key that is no longer pressed to false
    }
}

void ControllerGame::waitKeyToRestart() {
    while (key_.none()) { // while any key is not pressed
        while (al_get_next_event(queue_, &event_)) { // get the next event
            checkEventType();
        }
  }
    gameBoard_->resetTheLife();
    gameBoard_->resetTheScore();
    isGaming_ = true;
    win_ = false;
}

