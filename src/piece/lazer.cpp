/**
 * @file lazer.cpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Define the lazer class
 * @date 26/11/2024
 *
 */

#include "lazer.hpp"
#include "../global_variables.hpp"
#include "racket.hpp"

// ### Constructor ###
Lazer::Lazer(Racket racket) : Forme(racket.getCenter(), COLOR_RED), Rectangle(racket.getCenter(), 10, 20, COLOR_RED), racket_(racket), speed_(10) {}


// ### Public methods ###
void Lazer::draw() {
    moveUp();
    Rectangle::draw();
}

void Lazer::moveUp() {
    center_.y -= speed_;
}

// ### Getters ###
float Lazer::getX() const { return center_.x; }

float Lazer::getY() const { return center_.y; }

float Lazer::getSpeed() const { return speed_; }

// ### Setters ###
void Lazer::setX(const float x) { center_.x = x; }

void Lazer::setY(const float y) { center_.y = y; }

void Lazer::setSpeed(const float speed) { speed_ = speed; }
