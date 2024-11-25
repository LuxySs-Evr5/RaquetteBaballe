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
#include "colors/colors.hpp"
#include "life/life.hpp"
#include "score/score.hpp"


using namespace std;


void drawWallGame(){
    // draw the walls of the game
    al_draw_filled_rectangle(UPPER_WALL_X_START, UPPER_WALL_Y_START, SCREEN_WIDTH - SPACE_BTW_START_SCREEN_WALL, UPPER_WALL_Y_START + WALL_THICKNESS, COLOR_BLACK); // upper wall
    al_draw_filled_rectangle(LEFT_WALL_X_START, LEFT_WALL_Y_START, LEFT_WALL_X_START + WALL_THICKNESS, SCREEN_HEIGHT - SPACE_BTW_START_SCREEN_WALL, COLOR_BLACK); // left wall
    al_draw_filled_rectangle(RIGHT_WALL_X_START, RIGHT_WALL_Y_START, RIGHT_WALL_X_START + WALL_THICKNESS, SCREEN_HEIGHT - SPACE_BTW_START_SCREEN_WALL, COLOR_BLACK); // right wall
    al_draw_filled_rectangle(BOTTOM_WALL_X_START, BOTTOM_WALL_Y_START, SCREEN_WIDTH - SPACE_BTW_START_SCREEN_WALL, BOTTOM_WALL_Y_START + WALL_THICKNESS, COLOR_BLACK); // bottom wall
}

int main(int /* argc */, char ** /* argv */){

    if (initialize_allegro() != 0){
        return -1;
    }
        
    ALLEGRO_FONT *font = al_load_ttf_font("fonts/CaskaydiaCoveNerdFontMono-Regular.ttf", 24, 0); // the directory that allegro looks is the main directory
    if (!font){
        cerr << "Failed to load the font" << endl;
        return -1;
    }

    ALLEGRO_DISPLAY *display = al_create_display(static_cast<int>(SCREEN_WIDTH), static_cast<int>(SCREEN_HEIGHT));
    if (!display){
        cerr << "Failed to create a display" << endl;
        return -1;
    }

    ALLEGRO_TIMER *timer = al_create_timer(1.0 / FPS); 
    if (!timer){
        cerr << "Failed to create a timer" << endl;
        return -1;
    }

    ALLEGRO_EVENT_QUEUE *queue = al_create_event_queue();
    if (!queue){
        cerr << "Failed to create an event queue" << endl;
        return -1;
    }

    ALLEGRO_BITMAP *heartImage = al_load_bitmap("images/heart.png"); // the directory that allegro looks is the main directory
    if (!heartImage){
        cerr << "Failed to load the image" << endl;
        return -1;
    }

    ALLEGRO_SAMPLE *music = al_load_sample("music/arkanoid.wav");
    if (!music) {
        cerr << "Failed to load the music" << endl;
        return -1;
    }

    ALLEGRO_SAMPLE_INSTANCE *instanceMusic = al_create_sample_instance(music);
    if (!instanceMusic) {
        cerr << "Failed to create the sample instance" << endl;
        return -1;
    }

    if (!al_attach_sample_instance_to_mixer(instanceMusic, al_get_default_mixer())) {
        cerr << "Failed to attach sample instance to mixer." << endl;
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
            } 
            else if (event.type == ALLEGRO_EVENT_KEY_UP) {
                key[event.keyboard.keycode] = false; // set the key that is no longer pressed to false
        }
    
        }

        if (draw){
            draw = false;
            al_start_timer(timer);
            
            al_clear_to_color(COLOR_WHITE);

            int heartWidth = al_get_bitmap_width(heartImage);
            int heartHeight = al_get_bitmap_height(heartImage);

            float scaleHeartWidth = HEART_IMAGE_SIZE;
            float scaleHeartHeight = HEART_IMAGE_SIZE;

            float heartX = SCREEN_WIDTH / 4 + 40; // space between the text and the heart image
            
            for (float i = 0; i < life.getNbLifes(); ++i) {
                // draw the heart image at the right of the text Life
                al_draw_scaled_bitmap(heartImage, 0, 0, static_cast<float>(heartWidth), static_cast<float>(heartHeight), heartX + i * (scaleHeartWidth + 5), 50, scaleHeartWidth, scaleHeartHeight, 0);
            }

            al_draw_text(font, COLOR_BLACK, SCREEN_WIDTH / 2,30, ALLEGRO_ALIGN_CENTER, "Arkanoid");
            al_draw_text(font, COLOR_BLACK, SCREEN_WIDTH / 4, 50, ALLEGRO_ALIGN_CENTER, "Life : ");
            al_draw_text(font, COLOR_BLACK, 3 * SCREEN_WIDTH / 4, 50, ALLEGRO_ALIGN_CENTER, score.getScoreString().c_str());
            
            drawWallGame();
            canvas.draw();
            
            al_flip_display(); // update the window display
        }
    }

    al_destroy_display(display);
    al_destroy_event_queue(queue);
    al_destroy_timer(timer);
    return 0;

}