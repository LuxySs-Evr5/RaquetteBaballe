/**
 * @file in_game.cpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Class that manage the current game
 */

#include "in_game.hpp"
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>



#include "../init_allegro/initialize_allegro.hpp"
#include "../game_over/draw_game_over.hpp"
#include "../wall/wall_game.hpp"

// ### Constructor ###
InGame::InGame() {

    if (initialize_allegro() != 0){
        //TODO: verifier le exit
        exit(-1);
    }
    
    font24_ = al_load_ttf_font("fonts/CaskaydiaCoveNerdFontMono-Regular.ttf", 24, 0); // the directory that allegro looks is the main directory
    checkInit(font24_, "font24");

    font50_ = al_load_ttf_font("fonts/CaskaydiaCoveNerdFontMono-Regular.ttf", 50, 0); // the directory that allegro looks is the main directory
    checkInit(font50_, "font50");

    display_ = al_create_display(static_cast<int>(SCREEN_WIDTH), static_cast<int>(SCREEN_HEIGHT));
    checkInit(display_, "display");

    timer = al_create_timer(1.0 / FPS); 
    checkInit(timer, "timer");

    queue = al_create_event_queue();
    checkInit(queue, "event queue");

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

    al_register_event_source(queue, al_get_display_event_source(display_)); // register the display event source
    al_register_event_source(queue, al_get_keyboard_event_source()); // register the keyboard event source
    al_register_event_source(queue, al_get_mouse_event_source()); // register the mouse event source
    al_register_event_source(queue, al_get_timer_event_source(timer)); // register the timer event source

    al_set_sample_instance_playmode(instanceMusic_, ALLEGRO_PLAYMODE_LOOP); // read the music in loop

    al_play_sample_instance(instanceMusic_); // play the music
}


// ### Destructor ###
InGame::~InGame(){
    // destroy all
    al_destroy_display(display_);
    al_destroy_font(font24_);
    al_destroy_font(font50_);
    al_destroy_bitmap(heartImage_);
    al_destroy_event_queue(queue);
    al_destroy_timer(timer);
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

void InGame::gameOver(){
    score_.saveScore();
    drawGameOver(score_.getScore(), font50_);
    al_flip_display();

    while (true) {
        al_wait_for_event(queue, &event);                                

        if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
            break;
        }       
    }
    isGaming_ = true;
    life_.resetLife();
    score_.resetScore();
}

void InGame::moveRacket(const float x){
    canvas_.moveRacket(x);
}

void InGame::shootLazer(){
    canvas_.addLazer();
}

void InGame::drawGame(){
    draw_ = false;
    al_start_timer(timer);
    
    al_clear_to_color(COLOR_BLACK); // set the color of the window to black

    drawWallGame(COLOR_DARK_GREY);

    al_draw_text(font24_, COLOR_WHITE, SCREEN_WIDTH / 2,30, ALLEGRO_ALIGN_CENTER, "Arkanoid"); // draw the title
    al_draw_text(font24_, COLOR_WHITE, SCREEN_WIDTH / 4, 50, ALLEGRO_ALIGN_CENTER, "Life : "); // draw the text "Life : ", the hearts will be drawn at the right
    al_draw_text(font24_, COLOR_WHITE, 3 * SCREEN_WIDTH / 4, 50, ALLEGRO_ALIGN_CENTER, score_.getScoreString().c_str()); // draw the score
    
    life_.drawLife(heartImage_); // draw the hearts for the remaining lifes
    
    canvas_.draw(); // draw the pieces 
    
    if (isGaming_ == false) { // the game is over because no more lifes
        gameOver(); // display the game over screen
    }
    al_flip_display(); // update the window display
}


// ### Getters ###
bool InGame::getDone() const {
    return done_;
}

bool InGame::getDraw() const {
    return draw_;
}

bool InGame::getIsGaming() const {
    return isGaming_;
}

bool *InGame::getKey() {
    return key;
}


// ### Setters ###
void InGame::setDone(const bool done) {
    done_ = done;
}

void InGame::setDraw(const bool draw) {
    draw_ = draw;
}

void InGame::setIsGaming(const bool isGaming) {
    isGaming_ = isGaming;
}

