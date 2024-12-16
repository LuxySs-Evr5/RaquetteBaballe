/**
 * @file ball.cpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Define the class Ball
 * @date 26/11/2024
 *
 */

#include "ball_ui.hpp"

// ### Constructor ###
BallUi::BallUi(Point center, float radius, ALLEGRO_COLOR color)
    : Circle(center, radius, color) {}

// ### Public methods ###
void BallUi::draw() {

    center_.y =
        SCREEN_HEIGHT
        - center_.y; // Invert the y axis to match the screen with the backend
    Circle::draw();
}