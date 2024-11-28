/**
 * @file initialize_allegro.cpp
 * @author Ethan Van Ruyskensvelde (Main developper)
 * @brief This file contains the main function of the game Arkanoid that launches the game with allegro 
 * and manages the events
 * @date 24/11/2024
 *
 */

#include <allegro5/keycodes.h>
#include "in_game/in_game.hpp"

using namespace std;


int main(int /* argc */, char ** /* argv */){

    InGame inGame;

    al_start_timer(inGame.timer);
    
    while (inGame.getDone() == false) { // while the game is not done

        al_wait_for_event(inGame.queue, nullptr); // wait for an event

        while (al_get_next_event(inGame.queue, &inGame.event)) { // get the next event
            
            if (inGame.event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) { // if the display is closed
                inGame.setDone(true);
            }

            else if (inGame.event.type == ALLEGRO_EVENT_TIMER) {
                inGame.setDraw(true);
                al_stop_timer(inGame.timer);
                if (inGame.getKeys()[ALLEGRO_KEY_SPACE]) {
                        inGame.shootLazer();
                }
            } 

            else if (inGame.event.type == ALLEGRO_EVENT_KEY_DOWN) {
                inGame.setKeyTrue(inGame.event.keyboard.keycode); // set the key pressed to true
            } 

            else if (inGame.event.type == ALLEGRO_EVENT_KEY_UP) {
                inGame.setKeyFalse(inGame.event.keyboard.keycode); // set the key that is no longer pressed to false
            }
        }

        if (inGame.getDraw() == true) { // if the game have to be drawn
            inGame.drawGame(); // draw the game
        }
    }
    return 0;
}