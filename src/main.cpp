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
#include "canvas/canvas.hpp"
#include "init_allegro/initialize_allegro.hpp"
#include "init_allegro/check_init.hpp"
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
        
    ALLEGRO_FONT *font24 = al_load_ttf_font("fonts/CaskaydiaCoveNerdFontMono-Regular.ttf", 24, 0); // the directory that allegro looks is the main directory
    checkInit(font24, "font24");

    ALLEGRO_FONT *font50 = al_load_ttf_font("fonts/CaskaydiaCoveNerdFontMono-Regular.ttf", 50, 0); // the directory that allegro looks is the main directory
    checkInit(font50, "font50");

    ALLEGRO_DISPLAY *display = al_create_display(static_cast<int>(SCREEN_WIDTH), static_cast<int>(SCREEN_HEIGHT));
    checkInit(display, "display");

    ALLEGRO_TIMER *timer = al_create_timer(1.0 / FPS); 
    checkInit(timer, "timer");

    ALLEGRO_EVENT_QUEUE *queue = al_create_event_queue();
    checkInit(queue, "event queue");

    ALLEGRO_BITMAP *heartImage = al_load_bitmap("images/heart.png"); // the directory that allegro looks is the main directory
    checkInit(heartImage, "heart image");

    ALLEGRO_SAMPLE *music = al_load_sample("music/arkanoid.wav");
    checkInit(music, "music");

    ALLEGRO_SAMPLE_INSTANCE *instanceMusic = al_create_sample_instance(music);
    checkInit(instanceMusic, "instanceMusic");

    if (!al_attach_sample_instance_to_mixer(instanceMusic, al_get_default_mixer())) { // attach the sample instance to the mixer
        cerr << "Failed to attach sample instance to mixer" << endl;
        al_destroy_sample_instance(instanceMusic);
        al_destroy_sample(music);
        return -1;
    }


    al_register_event_source(queue, al_get_display_event_source(display)); // register the display event source
    al_register_event_source(queue, al_get_keyboard_event_source()); // register the keyboard event source
    al_register_event_source(queue, al_get_mouse_event_source()); // register the mouse event source
    al_register_event_source(queue, al_get_timer_event_source(timer)); // register the timer event source

    al_set_sample_instance_playmode(instanceMusic, ALLEGRO_PLAYMODE_LOOP); // read the music in loop

    al_play_sample_instance(instanceMusic); // play the music

    bool done = false;
    bool draw = false;

    ALLEGRO_EVENT event;

    Canvas canvas;
    Life life;
    Score score;

    bool key[ALLEGRO_KEY_MAX] = {false}; // table of all keyboard keys set to false 

    al_start_timer(timer);
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
            }
            al_flip_display(); // update the window display
        }
    }

    // destroy all
    al_destroy_display(display);
    al_destroy_font(font24);
    al_destroy_font(font50);
    al_destroy_bitmap(heartImage);
    al_destroy_event_queue(queue);
    al_destroy_timer(timer);
    al_destroy_sample_instance(instanceMusic);
    al_destroy_sample(music);
    return 0;

}