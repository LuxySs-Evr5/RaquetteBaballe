/**
 * @file gui_racket.cpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Define the racket class
 * @date 26/11/2024
 *
 */

#include "gui_racket.hpp"

// ### Constructor ###
GuiRacket::GuiRacket(Point center, float width, float height, ALLEGRO_COLOR color) : Forme(center, color), Rectangle(center, width, height, color) {}

// ### Public methods ###
void GuiRacket::draw() {
    Rectangle::draw();
}

void GuiRacket::moveHorizontally(const float x) {
    center_.x = x;
}

// ### Getters ###  
Point GuiRacket::getCenter() const { return center_; }

float GuiRacket::getX() const { return center_.x; }