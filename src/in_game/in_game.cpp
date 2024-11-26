/**
 * @file in_game.cpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Class that manage the current game
 */

#include "in_game.hpp"
#include <allegro5/timer.h>
#include <allegro5/display.h>
#include <allegro5/events.h>
#include <allegro5/keyboard.h>
#include <allegro5/mouse.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

// ### Constructor ###
InGame::InGame() {
    
    font24_ = al_load_ttf_font("fonts/CaskaydiaCoveNerdFontMono-Regular.ttf", 24, 0); // the directory that allegro looks is the main directory
    checkInit(font24_, "font24");

    font50_ = al_load_ttf_font("fonts/CaskaydiaCoveNerdFontMono-Regular.ttf", 50, 0); // the directory that allegro looks is the main directory
    checkInit(font50_, "font50");

    display_ = al_create_display(static_cast<int>(SCREEN_WIDTH), static_cast<int>(SCREEN_HEIGHT));
    checkInit(display_, "display");

    timer_ = al_create_timer(1.0 / FPS); 
    checkInit(timer_, "timer");

    queue_ = al_create_event_queue();
    checkInit(queue_, "event queue");

    heartImage_ = al_load_bitmap("images/heart.png"); // the directory that allegro looks is the main directory
    checkInit(heartImage_, "heart image");

    music_ = al_load_sample("music/arkanoid.wav");
    checkInit(music_, "music");

    instanceMusic_ = al_create_sample_instance(music_);
    checkInit(instanceMusic_, "instanceMusic");

    if (!al_attach_sample_instance_to_mixer(instanceMusic_, al_get_default_mixer())) { // attach the sample instance to the mixer
        cerr << "Failed to attach sample instance to mixer" << endl;
        al_destroy_sample_instance(instanceMusic_);
        al_destroy_sample(music_);
        //TODO: verifier le exit
        exit(-1);
    }

    al_register_event_source(queue_, al_get_display_event_source(display_)); // register the display event source
    al_register_event_source(queue_, al_get_keyboard_event_source()); // register the keyboard event source
    al_register_event_source(queue_, al_get_mouse_event_source()); // register the mouse event source
    al_register_event_source(queue_, al_get_timer_event_source(timer_)); // register the timer event source

    al_set_sample_instance_playmode(instanceMusic_, ALLEGRO_PLAYMODE_LOOP); // read the music in loop

    al_play_sample_instance(instanceMusic_); // play the music

    done_ = false;
    draw_ = false;
    event_ = ALLEGRO_EVENT();
    canvas_ = Canvas();
    life_ = Life();
    score_ = Score();
}


// ### Destructor ###
InGame::~InGame(){
    // destroy all
    al_destroy_display(display_);
    al_destroy_font(font24_);
    al_destroy_font(font50_);
    al_destroy_bitmap(heartImage_);
    al_destroy_event_queue(queue_);
    al_destroy_timer(timer_);
    al_destroy_sample_instance(instanceMusic_);
    al_destroy_sample(music_);
    al_uninstall_audio();
    al_uninstall_keyboard();
    al_uninstall_mouse();
    al_shutdown_image_addon();
    al_shutdown_font_addon();
    al_shutdown_ttf_addon();
    al_shutdown_primitives_addon();
    al_uninstall_system();
}


// ### Public methods ###
void InGame::checkInit(void *test,string type){
    if (test == nullptr){
        cerr << "Failed to load " << type << endl;
        exit(-1);
    }
}


// ### Getters ###
ALLEGRO_TIMER *InGame::getTimer() const {
    return timer_;
}

bool InGame::getDone() const {
    return done_;
}

bool InGame::getDraw() const {
    return draw_;
}

ALLEGRO_DISPLAY *InGame::getDisplay() const {
    return display_;
}

ALLEGRO_EVENT_QUEUE *InGame::getQueue() const {
    return queue_;
}

ALLEGRO_EVENT InGame::getEvent() const {
    return event_;
}

ALLEGRO_BITMAP *InGame::getHeartImage() const {
    return heartImage_;
}

ALLEGRO_SAMPLE *InGame::getMusic() const {
    return music_;
}

ALLEGRO_SAMPLE_INSTANCE *InGame::getInstanceMusic() const {
    return instanceMusic_;
}

ALLEGRO_FONT *InGame::getFont24() const {
    return font24_;
}

ALLEGRO_FONT *InGame::getFont50() const {
    return font50_;
}

Canvas InGame::getCanvas() const {
    return canvas_;
}

Life InGame::getLife() const {
    return life_;
}

Score InGame::getScore() const {
    return score_;
}

bool *InGame::getKey() {
    return key;
}

