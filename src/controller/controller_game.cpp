/**
 * @file controller_game.cpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Class that manage the current game
 */

#include "controller_game.hpp"
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>

#include <allegro5/mouse.h>
#include <iostream>
#include <memory>
#include <vector>

#include "../global_variables.hpp"

using namespace std;

// ### Constructor ###
ControllerGame::ControllerGame() {
  vector<shared_ptr<Brick>> bricks{
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{0, boardHeight - 1},
                                     Vec2{BRIK_WIDTH - 1, BRIK_HEIGHT}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{BRIK_WIDTH - 1, boardHeight - 1},
                                     Vec2{2 * BRIK_WIDTH - 1, BRIK_HEIGHT}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{2 * BRIK_WIDTH - 1, boardHeight - 1},
                                     Vec2{3 * BRIK_WIDTH - 1, BRIK_HEIGHT}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{3 * BRIK_WIDTH - 1, boardHeight - 1},
                                     Vec2{4 * BRIK_WIDTH - 1, BRIK_HEIGHT}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{4 * BRIK_WIDTH - 1, boardHeight - 1},
                                     Vec2{5 * BRIK_WIDTH - 1, BRIK_HEIGHT}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{5 * BRIK_WIDTH - 1, boardHeight - 1},
                                     Vec2{6 * BRIK_WIDTH - 1, BRIK_HEIGHT}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{6 * BRIK_WIDTH - 1, boardHeight - 1},
                                     Vec2{7 * BRIK_WIDTH - 1, BRIK_HEIGHT}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{7 * BRIK_WIDTH - 1, boardHeight - 1},
                                     Vec2{8 * BRIK_WIDTH - 1, BRIK_HEIGHT}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{8 * BRIK_WIDTH - 1, boardHeight - 1},
                                     Vec2{9 * BRIK_WIDTH - 1, BRIK_HEIGHT}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{9 * BRIK_WIDTH - 1, boardHeight - 1},
                                     Vec2{10 * BRIK_WIDTH - 1, BRIK_HEIGHT}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{10 * BRIK_WIDTH - 1, boardHeight - 1},
                                     Vec2{11 * BRIK_WIDTH - 1, BRIK_HEIGHT}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{11 * BRIK_WIDTH - 1, boardHeight - 1},
                                     Vec2{12 * BRIK_WIDTH - 1, BRIK_HEIGHT}})};

    Racket racket{BoundingBox{Vec2{RACKET_X_START - RACKET_WIDTH / 2,
                                   RACKET_Y_START - RACKET_HEIGHT / 2},
                              Vec2{RACKET_X_START + RACKET_WIDTH / 2,
                                   RACKET_Y_START + RACKET_HEIGHT / 2}}};

    vector<shared_ptr<Ball>> balls{make_shared<Ball>(
        Vec2{RACKET_X_START, RACKET_Y_START - RACKET_HEIGHT / 2 - BALL_RADIUS},
        Vec2{0, -1}, BALL_RADIUS)};

    model_ = make_shared<Model>(bricks, balls, racket);
    displayGame_ = make_shared<DisplayGame>(model_);

    
    if (!al_init()) { // initialize allegro
        cerr << "Failed to initialize Allegro" << endl;
        exit(-1);
    }

    if (!al_install_keyboard()) {
        cerr << "Failed to install the keyboard" << endl;
        exit(-1);
    }

    if (!al_install_mouse()) {
        cerr << "Failed to install the mouse" << endl;
        exit(-1);
    }

    timer_ = al_create_timer(1.0 / FPS);
    if (!timer_) {
        cerr << "Failed to create timer" << endl;
        exit(-1);
    }

    queue_ = al_create_event_queue();
    if (!queue_) {
        cerr << "Failed to create queue" << endl;
        exit(-1);
    }

    al_register_event_source(
        queue_,
        al_get_display_event_source(
            displayGame_->getDisplay())); // register the display event source
    al_register_event_source(
        queue_,
        al_get_keyboard_event_source()); // register the keyboard event source
    al_register_event_source(
        queue_, al_get_mouse_event_source()); // register the mouse event source
    al_register_event_source(
        queue_,
        al_get_timer_event_source(timer_)); // register the timer event source
    
}

// ### Destructor ###
ControllerGame::~ControllerGame() {
    al_destroy_event_queue(queue_);
    al_destroy_timer(timer_);
    al_uninstall_keyboard();
    al_uninstall_mouse();
}

// ### Public methods ###
void ControllerGame::process() {
    al_start_timer(timer_);

    while (!done_) { // while the game is not done

        // TODO: check if the game is lost because no more lifes

        al_wait_for_event(queue_, nullptr);

        while (al_get_next_event(queue_, &event_)) { // get the next event
            checkEventType();
        }

        if (draw_) {    // if the game have to be drawn
            drawGame(); // draw the game
        }
    }
}

// ### Private methods ###
void ControllerGame::drawGame() {
    al_start_timer(timer_);
    draw_ = false;

    if (isGaming_ == true) {              // if the game is running
        al_get_mouse_state(&mouseState_); // get the mouse state

        // check if the mouse is in the window
        if (mouseState_.x < 0) {
            mouseState_.x = 0;
        } else if (mouseState_.x > static_cast<int>(SCREEN_WIDTH)) {
            mouseState_.x = static_cast<int>(SCREEN_WIDTH);
        }

        model_->moveRacketHorizontal(static_cast<double>(mouseState_.x));

        // TODO:
        // controller.setRacketHorizontal(static_cast<double>(
        // mouseState_.x)); // move the racket with the mouse

        displayGame_->draw(); // draw the pieces
    }

    else if (isGaming_ == false) { // the game is over because no more lifes
        displayGame_->gameOver();   // display the game over screen
        waitKeyToRestart();
    }

    else if (win_ == true) {    // the game is won
        displayGame_->gameWin(); // display the game win screen
        waitKeyToRestart();
        // TODO: launch a new level
    }
}

void ControllerGame::checkLife() {
    if (model_->getNumberOfLifes() == 0) { // TODO: GameBoard or Model ?
        isGaming_ = false;
        model_->saveScore();
    }
}

void ControllerGame::checkEventType() {
    if (event_.type
        == ALLEGRO_EVENT_DISPLAY_CLOSE) { // if the display is closed
        done_ = true;
    }

    else if (event_.type == ALLEGRO_EVENT_TIMER) {
        model_->update(1.0 / FPS);
        al_stop_timer(timer_);
        draw_ = true;

        if (key_[ALLEGRO_KEY_SPACE]) {
            shootLazer();
        }
    }

    else if (event_.type == ALLEGRO_EVENT_KEY_DOWN) {
        key_.set(event_.keyboard.keycode, true); // set the key pressed to true
    }

    else if (event_.type == ALLEGRO_EVENT_KEY_UP) {
        key_.reset(
            event_.keyboard
                .keycode); // set the key that is no longer pressed to false
    }
}

void ControllerGame::waitKeyToRestart() {
    while (key_.none()) {
        checkEventType();
    }

    isGaming_ = true;
}
