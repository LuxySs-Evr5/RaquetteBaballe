/**
 * @file controller_game.cpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Class that manage the current game
 */

#include "controller_game.hpp"
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

#include <allegro5/mouse.h>
#include <iostream>

#include "../global_variables.hpp"

using namespace std;

// ### Constructor ###
ControllerGame::ControllerGame() {
    if (!al_init()) { // initialize allegro
        cerr << "Failed to initialize Allegro" << endl;
        exit(-1);
    }

    if(!al_install_keyboard()) {
        cerr << "Failed to install the keyboard" << endl;
        exit(-1);
    }

    if(!al_install_mouse()) {
        cerr << "Failed to install the mouse" << endl;
        exit(-1);
    }
  
    timer_ = al_create_timer(1.0 / FPS); 
    if (!timer_) {
        cerr << "Failed to create timer" << endl;
        exit(-1);
    }

    queue_ = al_create_event_queue();
    if (!queue_) {
        cerr << "Failed to create queue" << endl;
        exit(-1);
    }

    al_register_event_source(queue_, al_get_display_event_source(displayGame_.getDisplay())); // register the display event source
    al_register_event_source(queue_, al_get_keyboard_event_source()); // register the keyboard event source
    al_register_event_source(queue_, al_get_mouse_event_source()); // register the mouse event source
    al_register_event_source(queue_, al_get_timer_event_source(timer_)); // register the timer event source
}


// ### Destructor ###
ControllerGame::~ControllerGame(){
    al_destroy_event_queue(queue_);
    al_destroy_timer(timer_);
    al_uninstall_keyboard();
    al_uninstall_mouse();
}


// ### Public methods ###
void ControllerGame::process() {
    al_start_timer(timer_);
    
    while (done_ == false) { // while the game is not done

        al_wait_for_event(queue_, nullptr);

        while (al_get_next_event(queue_, &event_)) { // get the next event
            
            if (event_.type == ALLEGRO_EVENT_DISPLAY_CLOSE) { // if the display is closed
                done_ = true;
            }

            else if (event_.type == ALLEGRO_EVENT_TIMER) {
                al_stop_timer(timer_);
                draw_ = true;
                
                if (key_[ALLEGRO_KEY_SPACE]) {
                        shootLazer();
                }
            } 

            else if (event_.type == ALLEGRO_EVENT_KEY_DOWN) {
                key_[event_.keyboard.keycode] = true; // set the key pressed to true
            } 

            else if (event_.type == ALLEGRO_EVENT_KEY_UP) {
                key_[event_.keyboard.keycode] = false; // set the key that is no longer pressed to false
            }
        }

        if (draw_ == true) { // if the game have to be drawn
            drawGame(); // draw the game
        }
    }
}


void ControllerGame::drawGame() {
    draw_ = false;
    al_start_timer(timer_);
    al_get_mouse_state(&mouseState_); // get the mouse state
    
    // check if the mouse is in the window
    if (mouseState_.x < 0){
        mouseState_.x = 0;
    } else if (mouseState_.x > static_cast<int>(SCREEN_WIDTH)) {
        mouseState_.x = static_cast<int>(SCREEN_WIDTH);    
    }
    
    gameBoard_.moveRacket(static_cast<float>(mouseState_.x)); // move the racket with the mouse

    displayGame_.draw(); // draw the pieces

    if (isGaming_ == false) { // the game is over because no more lifes
        while (isGaming_ == false) { // the game is over because no more lifes
        displayGame_.gameOver(); // display the game over screen
        al_wait_for_event(queue_, &event_);                                

        if (event_.type == ALLEGRO_EVENT_KEY_DOWN) {
            break;
            }
        }
        isGaming_ = true;
        gameBoard_.life_.resetLife();
        gameBoard_.score_.resetScore();
        // TODO: launch a new level

    }

}