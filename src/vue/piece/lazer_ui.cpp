/**
 * @file lazer_ui.cpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Define the class LazerUi that will be used to draw the lazer
 * @date 31/12/2024
 *
 */

#include "lazer_ui.hpp"

LazerUi::LazerUi(Point center, float width, float height, ALLEGRO_COLOR color)
    : Rectangle(center, width, height, color) {}

void LazerUi::draw() {
    center_.y =
        SCREEN_HEIGHT
        - center_.y; // Invert the y axis to match the screen with the backend
    Rectangle::draw();
}
