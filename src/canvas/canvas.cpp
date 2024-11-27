/**
 * @file canvas.cpp
 * @author Ethan Van Ruyskensvelde (Main developper)
 * @brief Define the class Canvas that will be used to draw all the pieces of the game
 * @date 24/11/2024
 *
 */

#include "canvas.hpp"
#include "../global_variables.hpp"

using namespace std;


// ### Constructor ###
Canvas::Canvas() {
    racket_ = Racket();
    balls_.push_back(Ball());

    float startX = 100; // Position of the first brik on X
    float startY = 300; // Position of the first brik on Y
    float step = 60; // Space between briks

    for (float i = 0; i < 8; i++) {
        for (float j = 0; j < 14; j++) {
            briks_.push_back(Brik(Point(startX + (j * step), startY + (i * step)), BRIK_WIDTH, BRIK_HEIGHT, 1, 10, COLOR_RED));
        }
    }
};


// ### Public methods ###
void Canvas::draw() {
    for (auto &ball : balls_) {
        ball.draw();
    }

    for (auto &brik : briks_) {
        brik.draw();
    }

    racket_.draw();

    if (lazer_ != nullptr) {
        if (lazer_->getY() < 0) {
            lazer_.reset(nullptr);
        } else {
            lazer_->draw();
            lazer_->moveUp();
        }
    }

}

void Canvas::moveRacket(float x) {
    Racket newRacketPosition = racket_;
    newRacketPosition.moveHorizontally(x);
    float newX = newRacketPosition.getCenter().x;

    // Check if the racket is in the grid
    if ((newX - (racket_.getWidth() / 2) >= LEFT_WALL_X_START + WALL_THICKNESS) && (newX + (racket_.getWidth() / 2) <= RIGHT_WALL_X_START)) {
        racket_ = newRacketPosition;
    }
}

void Canvas::addLazer() {
    if (lazer_ == nullptr) {
        lazer_ = make_unique<Lazer>(Lazer(racket_));
    }
}


// ### Getters ###
Racket Canvas::getRacket() const {
    return racket_;
}