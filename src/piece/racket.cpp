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
Racket::Racket() : Forme(Point(500, 940), COLOR_WHITE), Rectangle(Point(500, 940), RACKET_WIDTH, RACKET_HEIGHT, COLOR_WHITE), speed_(RACKET_SPEED) {}


// ### Public methods ###
void Racket::draw() {
    Rectangle::draw();
}