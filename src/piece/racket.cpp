/**
 * @file racket.cpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Define the racket class
 * @date 26/11/2024
 *
 */

#include "racket.hpp"
#include "../global_variables.hpp"

// ### Constructor ###
Racket::Racket() : Forme(Point(RACKET_X_START, RACKET_Y_START), COLOR_WHITE), Rectangle(Point(RACKET_X_START, RACKET_Y_START), RACKET_WIDTH, RACKET_HEIGHT, COLOR_WHITE), speed_(RACKET_SPEED) {}


// ### Public methods ###
void Racket::draw() {
    Rectangle::draw();
}

// ### Getters ###  
Point Racket::getCenter() const { return center_; }

float Racket::getX() const { return center_.x; }