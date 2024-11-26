/**
 * @file initialize_allegro.cpp
 * @author Ethan Van Ruyskensvelde (Main developper)
 * @brief This file contains the main function of the game Arkanoid that launches the game with allegro 
 * and manages the events
 * @date 24/11/2024
 *
 */

#include <string>

#include "global_variables.hpp"
#include "in_game/in_game.hpp"
#include "canvas/canvas.hpp"
#include "colors/colors.hpp"
#include "life/life.hpp"
#include "score/score.hpp"
#include "wall/wall_game.hpp"
#include "game_over/draw_game_over.hpp"


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
                
                if (inGame.getKey()[ALLEGRO_KEY_A] || inGame.getKey()[ALLEGRO_KEY_Q]) { // if the key pressed is A or Q

                    inGame.moveRacket(-RACKET_SPEED); // speed of the racket is 20 but "-" because to the left
                } 
                if (inGame.getKey()[ALLEGRO_KEY_D] || inGame.getKey()[ALLEGRO_KEY_P]) { // if the key pressed is D or P
                    inGame.moveRacket(RACKET_SPEED); // speed of the racket is 20 to the right
                }
            } 

            else if (inGame.event.type == ALLEGRO_EVENT_KEY_DOWN) {
                inGame.getKey()[inGame.event.keyboard.keycode] = true; // set the key pressed to true
            } 

            else if (inGame.event.type == ALLEGRO_EVENT_KEY_UP) {
                inGame.getKey()[inGame.event.keyboard.keycode] = false; // set the key that is no longer pressed to false
            }
        }

        if (inGame.getDraw() == true) { // if the game have to be drawn
            inGame.setDraw(false);
            al_start_timer(inGame.timer);
            
            al_clear_to_color(COLOR_BLACK); // set the color of the window to black

            drawWallGame(COLOR_DARK_GREY);

            al_draw_text(inGame.getFont24(), COLOR_WHITE, SCREEN_WIDTH / 2,30, ALLEGRO_ALIGN_CENTER, "Arkanoid"); // draw the title
            al_draw_text(inGame.getFont24(), COLOR_WHITE, SCREEN_WIDTH / 4, 50, ALLEGRO_ALIGN_CENTER, "Life : "); // draw the text "Life : ", the hearts will be drawn at the right
            al_draw_text(inGame.getFont24(), COLOR_WHITE, 3 * SCREEN_WIDTH / 4, 50, ALLEGRO_ALIGN_CENTER, inGame.getScore().getScoreString().c_str()); // draw the score
            
            inGame.getLife().drawLife(inGame.getHeartImage()); // draw the hearts for the remaining lifes
            
            inGame.getCanvas().draw(); // draw the pieces 
            
            if (inGame.getIsGaming() == false) { // the game is over because no more lifes
                inGame.gameOver(); // display the game over screen
            }
            al_flip_display(); // update the window display
        }
    }
    return 0;
}