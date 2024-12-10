/**
 * @file display_game.cpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Class that manage the display of the game
 * @date 02/12/2024
 *
 */

#include "display_game.hpp"
#include "../color/colors.hpp"
#include "../../global_variables.hpp"
#include "../game_over/draw_game_over.hpp"
#include "../game_win/draw_game_win.hpp"
#include "../wall/wall_game.hpp"


#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_acodec.h>
#include <memory>

// ### Constructor ###
DisplayGame::DisplayGame(shared_ptr<GameBoard> gameBoard) : gameBoard_(gameBoard) {
  //TODO: verifier le exit
  initialize_allegro();

  font24_ = al_load_ttf_font("fonts/CaskaydiaCoveNerdFontMono-Regular.ttf", 24, 0); // the directory that allegro looks is the main directory
    checkInit(font24_, "font24");

  font50_ = al_load_ttf_font("fonts/CaskaydiaCoveNerdFontMono-Regular.ttf", 50, 0); // the directory that allegro looks is the main directory
  checkInit(font50_, "font50");

  display_ = al_create_display(static_cast<int>(SCREEN_WIDTH), static_cast<int>(SCREEN_HEIGHT));
  checkInit(display_, "display");

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

  al_set_sample_instance_playmode(instanceMusic_, ALLEGRO_PLAYMODE_LOOP); // read the music in loop
  al_play_sample_instance(instanceMusic_); // play the music
}



// ### Destructor ###
DisplayGame::~DisplayGame() {
  al_destroy_display(display_);
  al_destroy_font(font24_);
  al_destroy_font(font50_);
  al_destroy_bitmap(heartImage_);
  al_destroy_sample_instance(instanceMusic_);
  al_destroy_sample(music_);
  al_uninstall_audio();
  al_shutdown_image_addon();
  al_shutdown_font_addon();
  al_shutdown_ttf_addon();
  al_shutdown_primitives_addon();
}


// ### Private Methods ###
void DisplayGame::checkInit(void *test,string type){
    if (test == nullptr){
        cerr << "Failed to load " << type << endl;
        exit(-1);
    }
}

void DisplayGame::initialize_allegro() {

    if (!al_init()) { // initialize allegro
        cerr << "Failed to initialize Allegro" << endl;
        exit(-1);
    };  

    if (!al_init_primitives_addon()) { // initialize the primitives addon line, circle, rectangle, etc
        cerr << "Failed to initialize the primitives addon" << endl;
        exit(-1);
    }; 

    if (!al_install_audio()){ // install the audio
        cerr << "Failed to install audio" << endl;
        exit(-1);
    }

    if (!al_init_acodec_addon()) {
        cerr << "Failed to initialize the acodec addon" << endl;
        exit(-1);
    }

    if (!al_reserve_samples(1)) { // reserve the number of samples to play the sound
        cerr << "Failed to reserve samples" << endl;
        exit(-1);
    }

    if (!al_init_image_addon()) {
        cerr << "Failed to initialize the image addon" << endl;
        exit(-1);
    }  

    if (!al_init_font_addon()) { // initialize the police for the text
        cerr << "Failed to initialize the font addon" << endl;
        exit(-1);
    };

    if (!al_init_ttf_addon()) { // initialize the ttf for the text
        cerr << "Failed to initialize the ttf addon" << endl;
        exit(-1);
    }
}


// ### Public Methods ###
void DisplayGame::draw(){
al_clear_to_color(COLOR_BLACK); // set the color of the window to black
    drawWallGame(COLOR_DARK_GREY);

    al_draw_text(font24_, COLOR_WHITE, SCREEN_WIDTH / 2,30, ALLEGRO_ALIGN_CENTER, "Arkanoid"); // draw the title
    al_draw_text(font24_, COLOR_WHITE, SCREEN_WIDTH / 4, 50, ALLEGRO_ALIGN_CENTER, "Life : "); // draw the text "Life : ", the hearts will be drawn at the right
    al_draw_text(font24_, COLOR_WHITE, 3 * SCREEN_WIDTH / 4, 50, ALLEGRO_ALIGN_CENTER, gameBoard_->getStringScore().c_str()); // draw the score
    
    drawLife(); // draw the hearts for the remaining lifes
    
    //canvas_.moveRacket(static_cast<float>(mouseState_.x)); // move the racket with the mouse TODO: check to move racket

    canvas_.draw(); // draw the pieces 
    
    al_flip_display(); // update the window display
}


void DisplayGame::gameOver() {
  // TODO: verifier avec gameBoard  
    drawGameOver(gameBoard_->getIntScore(), font50_);
    al_flip_display();
}

void DisplayGame::gameWin() {
  drawGameWin(gameBoard_->getIntScore(), font50_);
  al_flip_display();
}

// ### Getters ###
ALLEGRO_DISPLAY *DisplayGame::getDisplay() const {
  return display_;
}


//### Private Methods ###
void DisplayGame::drawLife() {
  int heartWidth = al_get_bitmap_width(heartImage_);
  int heartHeight = al_get_bitmap_height(heartImage_);

  float scaleHeartWidth = HEART_IMAGE_SIZE;
  float scaleHeartHeight = HEART_IMAGE_SIZE;

  float heartX = SCREEN_WIDTH / 4 + 40; // space between the text and the heart image

  for (int i = 0; i < gameBoard_->getLife(); i++) {

    al_draw_scaled_bitmap(heartImage_, 0, 0, static_cast<float>(heartWidth), static_cast<float>(heartHeight), heartX + i * (scaleHeartWidth + 5), 50, scaleHeartWidth, scaleHeartHeight, 0); // Affiche les cœurs en haut à gauche
  }
}