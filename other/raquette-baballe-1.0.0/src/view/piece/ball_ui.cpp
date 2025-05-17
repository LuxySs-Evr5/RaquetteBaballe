/**
 * @file ball_ui.cpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Define the class BallUi
 * @date 26/11/2024
 *
 */

#include "ball_ui.hpp"

BallUi::BallUi(Point center, float radius, ALLEGRO_COLOR color)
    : Circle(center, radius, color) {}

void BallUi::draw() {
    center_.y =
        SCREEN_HEIGHT
        - center_.y; // Invert the y axis to match the screen with the backend
    Circle::draw();
}
