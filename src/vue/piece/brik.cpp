/**
 * @file brik.cpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Define the class Brik
 * @date 27/11/2024 
 *
 */

#include "brik.hpp"

// ### Constructor ###
Brik::Brik(Point center, float width, float height, int life, int scoreDestroy, ALLEGRO_COLOR color) : Rectangle(center, width, height, color), life_(life), scoreDestroy_(scoreDestroy) {}


// ### Public methods ###
void Brik::draw() {
    Rectangle::draw();
}


// ### Getters ###
int Brik::getLife() const { return life_; }

int Brik::getScoreDestroy() const { return scoreDestroy_; }