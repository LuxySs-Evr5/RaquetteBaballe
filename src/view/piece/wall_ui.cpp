/**
 * @file wall_ui.cpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Define the WallUi class
 * @date 26/11/2024
 *
 */

#include "wall_ui.hpp"

#include <allegro5/color.h>

WallUi::WallUi(Point center, float width, float height, ALLEGRO_COLOR color)
    : Rectangle(center, width, height, color) {}

void WallUi::draw() {
    center_.y =
        SCREEN_HEIGHT
        - center_.y; // Invert the y axis to match the screen with the backend
    Rectangle::draw();
}
