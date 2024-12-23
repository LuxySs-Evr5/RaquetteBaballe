/**
 * @file brik_ui.cpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Define the class Brik
 * @date 27/11/2024
 *
 */

#include "brick_ui.hpp"

// ### Constructor ###
BrickUi::BrickUi(Point center, float width, float height, ALLEGRO_COLOR color)
    : Rectangle(center, width, height, color) {}

// ### Public methods ###
void BrickUi::draw() {
    center_.y =
        SCREEN_HEIGHT
        - center_.y; // Invert the y axis to match the screen with the backend
    Rectangle::draw();
}

void BrickUi::setFrameColor(const ALLEGRO_COLOR &color) { frameColor_ = color; }