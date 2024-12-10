/**
 * @file racket.cpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Define the racket class
 * @date 26/11/2024
 *
 */

#include "racket_ui.hpp"
#include "../../global_variables.hpp"

// ### Constructor ###
RacketUi::RacketUi() : Rectangle(Point(RACKET_X_START, RACKET_Y_START), RACKET_WIDTH, RACKET_HEIGHT, COLOR_WHITE), speed_(RACKET_SPEED) {}


// ### Public methods ###
void RacketUi::draw() {
    Rectangle::draw();
}

void RacketUi::moveHorizontally(const float x) {
    center_.x = x;
}

// ### Getters ###  
Point RacketUi::getCenter() const { return center_; }

float RacketUi::getX() const { return center_.x; }