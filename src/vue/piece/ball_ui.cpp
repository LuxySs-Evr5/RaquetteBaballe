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
void BallUi::draw() { Circle::draw(); }

// this isn't needed anymore
// void BallUi::moveBall(const float x, const float y) {
//     center_.x += x;
//     center_.y += y;
// };
