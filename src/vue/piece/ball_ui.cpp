/**
 * @file ball.cpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Define the class Ball
 * @date 26/11/2024
 *
 */

#include "ball_ui.hpp"
#include "../../global_variables.hpp"

// ### Constructor ###
BallUi::BallUi() : Circle(Point(500, 900), BALL_RADIUS, COLOR_BLUE){}

// ### Public methods ###
void BallUi::draw() {
    Circle::draw();
}

void BallUi::moveBall(const float x, const float y){
    center_.x += x;
    center_.y += y;
};
