/**
 * @file gui_brik.cpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Define the class Brik
 * @date 27/11/2024 
 *
 */

#include "gui_brik.hpp"

// ### Constructor ###
GuiBrik::GuiBrik(Point center, float width, float height, ALLEGRO_COLOR color) : Forme(center, color), Rectangle(center, width, height, color) {}

// ### Public methods ###
void GuiBrik::draw() {
    Rectangle::draw();
}