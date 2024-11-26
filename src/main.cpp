/**
 * @file initialize_allegro.cpp
 * @author Ethan Van Ruyskensvelde (Main developper)
 * @brief This file contains the main function of the game Arkanoid that launches the game with allegro 
 * and manages the events
 * @date 24/11/2024
 *
 */

#include <allegro5/allegro.h>
#include <allegro5/bitmap.h>
#include <allegro5/display.h>
#include <allegro5/drawing.h>
#include <allegro5/events.h>
#include <allegro5/keyboard.h>
#include <allegro5/mouse.h>
#include <allegro5/system.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/timer.h>
#include <allegro5/keycodes.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

#include <iostream>
#include <string>

#include "global_variables.hpp"
#include "in_game/in_game.hpp"
#include "canvas/canvas.hpp"
#include "init_allegro/initialize_allegro.hpp"
#include "colors/colors.hpp"
#include "life/life.hpp"
#include "score/score.hpp"
#include "wall/wall_game.hpp"
#include "game_over/draw_game_over.hpp"


using namespace std;


int main(int /* argc */, char ** /* argv */){

    if (initialize_allegro() != 0){
        return -1;
    }

    InGame inGame;  

    al_start_timer(inGame.getTimer());
    while (!done){
        al_wait_for_event(queue, nullptr); // wait for an event
        while (al_get_next_event(queue, &event)) { // get the next event
            if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) { // if the display is closed
                done = true;
            }
            else if (event.type == ALLEGRO_EVENT_TIMER) {
                draw = true;
                al_stop_timer(timer);

                if (key[ALLEGRO_KEY_A] || key[ALLEGRO_KEY_Q]) { // if the key pressed is A or Q

                    canvas.moveRacket(-RACKET_SPEED); // speed of the racket is 20 but "-" because to the left
                } 
                if (key[ALLEGRO_KEY_D] || key[ALLEGRO_KEY_P]) { // if the key pressed is D or P
                    canvas.moveRacket(RACKET_SPEED); // speed of the racket is 20 to the right
                }
            } 
            else if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
                key[event.keyboard.keycode] = true; // set the key pressed to true
                if (!life.currentlyGaming()){
                    life.setGaming(true);
                    life.setNbLifes(3);
                    score.resetScore();
                }
            } 
            else if (event.type == ALLEGRO_EVENT_KEY_UP) {
                key[event.keyboard.keycode] = false; // set the key that is no longer pressed to false
        }
    
        }

        if (draw){
            draw = false;
            al_start_timer(timer);
            
            al_clear_to_color(COLOR_BLACK);

            life.drawLife(heartImage);

            al_draw_text(font24, COLOR_WHITE, SCREEN_WIDTH / 2,30, ALLEGRO_ALIGN_CENTER, "Arkanoid");
            al_draw_text(font24, COLOR_WHITE, SCREEN_WIDTH / 4, 50, ALLEGRO_ALIGN_CENTER, "Life : ");
            al_draw_text(font24, COLOR_WHITE, 3 * SCREEN_WIDTH / 4, 50, ALLEGRO_ALIGN_CENTER, score.getScoreString().c_str());
            
            drawWallGame(COLOR_DARK_GREY);
            canvas.draw();

            if (life.currentlyGaming() == false) { // the game is over because no more lifes
                //TODO: il fut que saveScore qui sauve dans le fichier score.txt fonctionne !
                score.saveScore();
                drawGameOver(score.getScore(), font50);
                al_flip_display();
                while (event.type != ALLEGRO_EVENT_KEY_DOWN) {               
                }
            }
            al_flip_display(); // update the window display
        }
    }
    
    return 0;

}