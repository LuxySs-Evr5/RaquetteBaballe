/**
 * @file controller_game.cpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Class that manage the current game
 */

#include "controller_game.hpp"
#include "../global_variables.hpp"

#include <allegro5/allegro.h>

#include <iostream>
#include <ostream>

using namespace std;

// TODO : Arrêter toutes les ressoucrces quand y a le message de game over ou de
// win (autres affichages allegro et le backend)
// TODO : Problème lors du chargement d'un niveau

// ### Constructor ###
ControllerGame::ControllerGame() : gameBoard_{make_shared<GameBoard>()} {
    displayGame_ = make_shared<DisplayGame>(gameBoard_);
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

    timer_ =
        al_create_timer(1.0 / 360); // TODO: check the FPS we want for allegro
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

    loadLevel(); // at the start of the game we start a level // TODO: check if
                 // good
}

// ### Destructor ###
ControllerGame::~ControllerGame() {}

// ### Public methods ###
void ControllerGame::process() {
    while (!done_) {

        currentTime_ = al_get_time();                // Actual time
        double deltaTime = currentTime_ - lastTime_; // Time between two frames
        lastTime_ = currentTime_;                    // Update the last time

        al_get_mouse_state(&mouseState_); // get the mouse state

        // check if the mouse is in the window // TODO: check si c'est utile
        if (mouseState_.x < 0) {
            mouseState_.x = 0;
        } else if (mouseState_.x > static_cast<int>(SCREEN_WIDTH)) {
            mouseState_.x = static_cast<int>(SCREEN_WIDTH);
        }

        gameBoard_->setRacketAtX(static_cast<double>(
            mouseState_.x)); // move the racket with the mouse

        gameBoard_->update(deltaTime);

        checkGameOver(); // check if the player has lifes // TODO : check if
                         // it's the right place to do that
        checkWin();      // check if the player has won

        al_wait_for_event(queue_, nullptr);

        while (al_get_next_event(queue_, &event_)) { // get the next event
            checkEventType();
        }

        if (draw_) {
            drawGame();
        }
    }
}

// ### Private methods ###

void ControllerGame::drawGame() {
    al_start_timer(timer_);
    draw_ = false;

    displayGame_->draw(); // draw the pieces
}

void ControllerGame::checkGameOver() {
    if (gameBoard_->getLife() == 0) {
        al_stop_timer(timer_);
        gameBoard_->saveCurrentScore();
        gameBoard_->clear(); // TODO: check if we do that ?
        gameBoard_->resetLifeCounter();
        gameBoard_->resetScore();
        displayGame_->gameOver();
        waitKeyToRestart();
    }
}
void ControllerGame::checkWin() {
    if (gameBoard_->getNumBricks()
        == 0) { // if there is no more bricks // TODO: not working
        al_stop_timer(timer_);
        gameBoard_->saveCurrentScore();
        gameBoard_->clear(); // TODO: check if we do that ?
        gameBoard_->resetLifeCounter();
        gameBoard_->resetScore();
        displayGame_->gameWin();
        waitKeyToRestart();
    }
}

void ControllerGame::checkEventType() {
    if (event_.type
        == ALLEGRO_EVENT_DISPLAY_CLOSE) { // if the display is closed
        done_ = true;
    }

    else if (event_.type == ALLEGRO_EVENT_TIMER) {
        al_stop_timer(timer_);
        draw_ = true;

        if (key_[ALLEGRO_KEY_SPACE]) {
            // shootLazer(); TODO : shoot lazer when bonus
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
    al_wait_for_event(queue_, nullptr);
    while (!(event_.type
             == ALLEGRO_EVENT_KEY_DOWN)) { // wait for a key to be pressed
        al_get_next_event(queue_, &event_);
        if (event_.type
            == ALLEGRO_EVENT_DISPLAY_CLOSE) { // if the display is closed
            done_ = true;
            break;
        }
    }
    loadLevel(); // TODO: check if it's the right place to do that
}

void ControllerGame::loadLevel() {
    const std::vector<std::shared_ptr<Ball>> balls = {
        std::make_shared<Ball>(Vec2{450, 85}, Vec2{0, 1}, 10, 500)};

    const std::vector<std::shared_ptr<Brick>> bricks{
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{50, 800}, Vec2{100, 775}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{125, 800}, Vec2{175, 775}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{200, 800}, Vec2{250, 775}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{275, 800}, Vec2{325, 775}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{350, 800}, Vec2{400, 775}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{425, 800}, Vec2{475, 775}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{500, 800}, Vec2{550, 775}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{575, 800}, Vec2{625, 775}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{650, 800}, Vec2{700, 775}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{725, 800}, Vec2{775, 775}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{800, 800}, Vec2{850, 775}}),

        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{50, 750}, Vec2{100, 725}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{125, 750}, Vec2{175, 725}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{200, 750}, Vec2{250, 725}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{275, 750}, Vec2{325, 725}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{350, 750}, Vec2{400, 725}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{425, 750}, Vec2{475, 725}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{500, 750}, Vec2{550, 725}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{575, 750}, Vec2{625, 725}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{650, 750}, Vec2{700, 725}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{725, 750}, Vec2{775, 725}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{800, 750}, Vec2{850, 725}}),

        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{50, 700}, Vec2{100, 675}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{125, 700}, Vec2{175, 675}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{200, 700}, Vec2{250, 675}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{275, 700}, Vec2{325, 675}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{350, 700}, Vec2{400, 675}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{425, 700}, Vec2{475, 675}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{500, 700}, Vec2{550, 675}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{575, 700}, Vec2{625, 675}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{650, 700}, Vec2{700, 675}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{725, 700}, Vec2{775, 675}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{800, 700}, Vec2{850, 675}}),

        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{50, 650}, Vec2{100, 625}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{125, 650}, Vec2{175, 625}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{200, 650}, Vec2{250, 625}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{275, 650}, Vec2{325, 625}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{350, 650}, Vec2{400, 625}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{425, 650}, Vec2{475, 625}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{500, 650}, Vec2{550, 625}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{575, 650}, Vec2{625, 625}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{650, 650}, Vec2{700, 625}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{725, 650}, Vec2{775, 625}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{800, 650}, Vec2{850, 625}}),

        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{50, 600}, Vec2{100, 575}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{125, 600}, Vec2{175, 575}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{200, 600}, Vec2{250, 575}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{275, 600}, Vec2{325, 575}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{350, 600}, Vec2{400, 575}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{425, 600}, Vec2{475, 575}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{500, 600}, Vec2{550, 575}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{575, 600}, Vec2{625, 575}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{650, 600}, Vec2{700, 575}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{725, 600}, Vec2{775, 575}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{800, 600}, Vec2{850, 575}}),

        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{50, 550}, Vec2{100, 525}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{125, 550}, Vec2{175, 525}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{200, 550}, Vec2{250, 525}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{275, 550}, Vec2{325, 525}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{350, 550}, Vec2{400, 525}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{425, 550}, Vec2{475, 525}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{500, 550}, Vec2{550, 525}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{575, 550}, Vec2{625, 525}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{650, 550}, Vec2{700, 525}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{725, 550}, Vec2{775, 525}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{800, 550}, Vec2{850, 525}}),

        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{50, 500}, Vec2{100, 475}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{125, 500}, Vec2{175, 475}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{200, 500}, Vec2{250, 475}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{275, 500}, Vec2{325, 475}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{350, 500}, Vec2{400, 475}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{425, 500}, Vec2{475, 475}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{500, 500}, Vec2{550, 475}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{575, 500}, Vec2{625, 475}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{650, 500}, Vec2{700, 475}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{725, 500}, Vec2{775, 475}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{800, 500}, Vec2{850, 475}})};

    const std::vector<std::shared_ptr<Border>> borders = {
        // TODO: Lucas doit voir : Les murs font partie de la grille
        // (0, 0) -> (0 + boardBoundingsThickness - 1, boardHeight - 1) // left
        // wall
        std::make_shared<Border>(
            Border{BoundingBox{Vec2{0, 0}, Vec2{BOARD_BOUNDINGS_THICKNESS - 1,
                                                BOARD_HEIGHT - 1}}}),
        // (0, boardHeight - 1) -> (boardWidth - 1, boardHeight -
        // boardBoundingsThickness - 1) // upper wall
        std::make_shared<Border>(
            BoundingBox{Vec2{0, BOARD_HEIGHT - 1},
                        Vec2{BOARD_WIDTH - 1,
                             BOARD_HEIGHT - BOARD_BOUNDINGS_THICKNESS - 1}}),
        // (boardWidth - boardBoundingsThickness - 1, 0) -> (boardWidth - 1,
        // boardHeight - 1) // right wall
        std::make_shared<Border>(
            BoundingBox{Vec2{BOARD_WIDTH - BOARD_BOUNDINGS_THICKNESS - 1, 0},
                        Vec2{BOARD_WIDTH - 1, BOARD_HEIGHT - 1}})};

    // Racket racket;
    // NOTE: doing this to get an iterator without having to rewrite it myself
    const std::vector<std::shared_ptr<Racket>> rackets{
        std::make_shared<Racket>(BoundingBox{Vec2{450, 50}, 100, 25})};

    gameBoard_->setRacket(rackets);
    gameBoard_->setBalls(balls);
    gameBoard_->setBorders(borders);
    gameBoard_->setBricks(bricks);

    al_start_timer(timer_);
    lastTime_ = al_get_time(); // get the time at the beginning of the game
}
