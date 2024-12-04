/**
 * @file gui_ball.cpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Define the class Ball
 * @date 26/11/2024
 *
 */

#include "gui_ball.hpp"
#include "../../global_variables.hpp"

// ### Constructor ###
GuiBall::GuiBall() : Forme(Point(500, 900), COLOR_BLUE), Circle(Point(500, 900), BALL_RADIUS, COLOR_BLUE), speedX_(5), speedY_(5) {}

GuiBall::GuiBall(Point center, float radius, ALLEGRO_COLOR color) : Forme(center, color), Circle(center, radius, color) {}

// ### Public methods ###
void GuiBall::draw() {
    Circle::draw();
}

void GuiBall::moveBall(const float x, const float y){
    center_.x += x;
    center_.y += y;
};

// ### Getters ###
float GuiBall::getSpeedX() const { return speedX_; }

float GuiBall::getSpeedY() const { return speedY_; }

// ### Setters ###
void GuiBall::setSpeedX(const float speedX) { speedX_ = speedX; }

void GuiBall::setSpeedY(const float speedY) { speedY_ = speedY; }

void GuiBall::setCenter(const int x, const int y) {
    center_.x = x;
    center_.y = y;
}
