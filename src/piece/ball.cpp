/**
 * @file ball.cpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Define the class Ball
 * @date 26/11/2024
 *
 */

#include "ball.hpp"
#include "../global_variables.hpp"

// ### Constructor ###
Ball::Ball() : Forme(Point(500, 900), COLOR_BLUE), Circle(Point(500, 900), BALL_RADIUS, COLOR_BLUE), speedX_(5), speedY_(5) {}

// ### Public methods ###
void Ball::draw(){
    Circle::draw();
}


// ### Getters ###
float Ball::getSpeedX() const { return speedX_; }

float Ball::getSpeedY() const { return speedY_; }

// ### Setters ###
void Ball::setSpeedX(const float speedX) { speedX_ = speedX; }

void Ball::setSpeedY(const float speedY) { speedY_ = speedY; }
