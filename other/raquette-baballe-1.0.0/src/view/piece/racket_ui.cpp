/**
 * @file racket_ui.cpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Define the racketUi class
 * @date 26/11/2024
 *
 */

#include "racket_ui.hpp"

RacketUi::RacketUi(Point center, float width, float height, ALLEGRO_COLOR color)
    : Rectangle(center, width, height, color) {}

void RacketUi::draw() {
    center_.y =
        SCREEN_HEIGHT
        - center_.y; // Invert the y axis to match the screen with the backend
    Rectangle::draw();
}
