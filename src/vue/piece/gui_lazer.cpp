/**
 * @file gui_lazer.cpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Define the lazer class
 * @date 26/11/2024
 *
 */

#include "gui_lazer.hpp"
#include "../../global_variables.hpp"
#include "gui_racket.hpp"

// ### Constructor ###
GuiLazer::GuiLazer(GuiRacket racket) : Forme(Point(racket.getX(), LAZER_Y_CENTER), COLOR_ORANGE), Rectangle(Point(racket.getX(), LAZER_Y_CENTER), LAZER_WIDTH, LAZER_HEIGHT, COLOR_ORANGE), speed_(LAZER_SPEED) {}

// ### Public methods ###
void GuiLazer::draw() {
    moveUp();
    Rectangle::draw();
}

void GuiLazer::moveUp() {
    center_.y -= speed_;
}

// ### Getters ###
float GuiLazer::getX() const { return center_.x; }

float GuiLazer::getY() const { return center_.y; }

float GuiLazer::getSpeed() const { return speed_; }

// ### Setters ###
void GuiLazer::setX(const float x) { center_.x = x; }

void GuiLazer::setY(const float y) { center_.y = y; }

void GuiLazer::setSpeed(const float speed) { speed_ = speed; }
