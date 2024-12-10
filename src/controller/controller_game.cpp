/**
 * @file controller_game.cpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Class that manage the current game
 */

#include "controller_game.hpp"

#include <allegro5/allegro.h>

#include <thread>

using namespace std;

constexpr std::chrono::duration<double> SLEEP_TIME(1.0f);

// ### Constructor ###
ControllerGame::ControllerGame() : gameBoard_{make_shared<GameBoard>()} {

    displayGame_ = make_shared<DisplayGame>(gameBoard_);

if (!al_init()) { // initialize allegro
        cerr << "Failed to initialize Allegro" << endl;
        exit(-1);
    }

    if(!al_install_keyboard()) {
        cerr << "Failed to install the keyboard" << endl;
        exit(-1);
    }

    if(!al_install_mouse()) {
        cerr << "Failed to install the mouse" << endl;
        exit(-1);
    }
  
    timer_ = al_create_timer(1.0 / 60); 
    if (!timer_) {
        cerr << "Failed to create timer" << endl;
        exit(-1);
    }

    queue_ = al_create_event_queue();
    if (!queue_) {
        cerr << "Failed to create queue" << endl;
        exit(-1);
    }

    al_register_event_source(queue_, al_get_display_event_source(displayGame_->getDisplay())); // register the display event source
    al_register_event_source(queue_, al_get_keyboard_event_source()); // register the keyboard event source
    al_register_event_source(queue_, al_get_mouse_event_source()); // register the mouse event source
    al_register_event_source(queue_, al_get_timer_event_source(timer_)); // register the timer event source
}


// ### Destructor ###
ControllerGame::~ControllerGame() {}

// ### Public methods ###
void ControllerGame::process() {
    using clock = std::chrono::high_resolution_clock;
    using time_point = std::chrono::time_point<clock>;
    using duration = std::chrono::duration<double>;

    time_point t_last_update =
        clock::now() - std::chrono::duration_cast<clock::duration>(SLEEP_TIME);

    while (!done_) {

        displayGame_->draw();
        cout << "draw" << endl;

        time_point t_now = clock::now();

        duration delta_time = t_now - t_last_update;

        t_last_update = t_now;

        gameBoard_->update(delta_time.count());

        // Gestion du temps
        std::cout << "delta time= " << delta_time.count() << std::endl;
        std::this_thread::sleep_for(std::chrono::duration<double>(SLEEP_TIME));
    }
}

void ControllerGame::drawGame() {}

void ControllerGame::checkLife() {}

// ### Private methods ###

void ControllerGame::checkEventType() {}

void ControllerGame::waitKeyToRestart() {}
