#include "initialize_allegro.hpp"

#include <allegro5/allegro.h>
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
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

#include <iostream>

using namespace std;

int initialize_allegro() {

    if (!al_init()) { // initialize allegro
        cerr << "Failed to initialize Allegro" << endl;
        return -1;
    };  

    if(!al_install_keyboard()) { // initialize the keyboard
        cerr << "Failed to install the keyboard" << endl;
        return -1;
    };

    if(!al_install_mouse()) { // initialize the mouse
        cerr << "Failed to install the mouse" << endl;
        return -1;
    };

    if (!al_init_primitives_addon()) { // initialize the primitives addon line, circle, rectangle, etc
        cerr << "Failed to initialize the primitives addon" << endl;
        return -1;
    }; 

    if (!al_install_audio()){ // install the audio
        cerr << "Failed to install audio" << endl;
        return -1;
    }

    if (!al_init_acodec_addon()) {
        cerr << "Failed to initialize the acodec addon" << endl;
        return -1;
    }

    if (!al_reserve_samples(1)) { // reserve the number of samples to play the sound
        cerr << "Failed to reserve samples" << endl;
        return -1;
    }

    if (!al_init_image_addon()) {
        cerr << "Failed to initialize the image addon" << endl;
        return -1;
    }  

    if (!al_init_font_addon()) { // initialize the police for the text
        cerr << "Failed to initialize the font addon" << endl;
        return -1;
    };

    if (!al_init_ttf_addon()) { // initialize the ttf for the text
        cerr << "Failed to initialize the ttf addon" << endl;
        return -1;
    }
    else {
        return 0;
    }
}