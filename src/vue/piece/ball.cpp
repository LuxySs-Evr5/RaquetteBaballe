/**
 * @file ball.cpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Define the class Ball
 * @date 26/11/2024
 *
 */

#include "ball.hpp"
#include "../../global_variables.hpp"

// ### Constructor ###
Ball::Ball() : Circle(Point(500, 900), BALL_RADIUS, COLOR_BLUE), speedX_(5), speedY_(5) {}

// ### Public methods ###
void Ball::draw() {
    Circle::draw();
}

void Ball::moveBall(const float x, const float y){
    center_.x += x;
    center_.y += y;
};

// ### Getters ###
float Ball::getSpeedX() const { return speedX_; }

float Ball::getSpeedY() const { return speedY_; }
