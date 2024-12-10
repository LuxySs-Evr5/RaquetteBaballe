/**
 * @file display_game.cpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Class that manage the display of the game
 * @date 02/12/2024
 *
 */

#include "display_game.hpp"
#include "../color/colors.hpp"

#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_acodec.h>
#include <memory>

// ### Constructor ###
DisplayGame::DisplayGame(shared_ptr<GameBoard> gameBoard) {
    //TODO: verifier le exit
  initialize_allegro();

  display_ = al_create_display(static_cast<int>(1000), static_cast<int>(1000));
  checkInit(display_, "display");
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
    al_clear_to_color(COLOR_WHITE); // set the color of the window to black
    
    al_flip_display(); // update the window display
}

// ### Getters ###
ALLEGRO_DISPLAY *DisplayGame::getDisplay() const {
  return display_;
}
