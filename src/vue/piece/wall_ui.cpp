/**
 * @file wall_ui.cpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Define the racket class
 * @date 26/11/2024
 *
 */

#include "wall_ui.hpp"
#include <allegro5/color.h>

// TODO : Removing magic numbers and set Global variables

// ### Constructor ###
// TODO: do we still need the default constructor ?
WallUi::WallUi() : Rectangle(Point(0, 0), 0, 0, COLOR_WHITE) {}

WallUi::WallUi(Point center, float width, float height, ALLEGRO_COLOR color)
    : Rectangle(center, width, height, color) {}

// ### Public methods ###
void WallUi::draw() { 
    center_.x = 25 + center_.x; // Add the offset to match the screen with the backend (thickness of the wall)
    center_.y = 1000 - center_.y; // Invert the y axis to match the screen with the backend
    Rectangle::draw(); }
