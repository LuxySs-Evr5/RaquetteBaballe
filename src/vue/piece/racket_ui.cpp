/**
 * @file racket.cpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Define the racket class
 * @date 26/11/2024
 *
 */

#include "racket_ui.hpp"
#include <allegro5/color.h>

// ### Constructor ###
// TODO: do we still need the default constructor ?
RacketUi::RacketUi() : Rectangle(Point(0, 0), 0, 0, COLOR_WHITE) {}

RacketUi::RacketUi(Point center, float width, float height, ALLEGRO_COLOR color)
    : Rectangle(center, width, height, color) {}

// ### Public methods ###
void RacketUi::draw() { Rectangle::draw(); }

void RacketUi::moveHorizontally(const float x) { center_.x = x; }

// ### Getters ###
Point RacketUi::getCenter() const { return center_; }

float RacketUi::getX() const { return center_.x; }
