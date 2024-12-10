/**
 * @file brik.cpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Define the class Brik
 * @date 27/11/2024
 *
 */

#include "brik_ui.hpp"

// ### Constructor ###
BrikUi::BrikUi(Point center, float width, float height, Color color)
    : Rectangle(center, width, height, color) {}

// ### Public methods ###
void BrikUi::draw() { Rectangle::draw(); }
