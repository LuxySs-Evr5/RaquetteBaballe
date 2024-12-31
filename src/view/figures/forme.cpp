/**
 * @file forme.cpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Define the class parent Forme and the class fille Circle and Rectangle
 * @date 16/11/2024
 *
 */

#include "forme.hpp"
#include <allegro5/allegro_primitives.h>

// ### class Rectangle ###
Rectangle::Rectangle(Point center, float width, float height,
                     ALLEGRO_COLOR fillColor, ALLEGRO_COLOR frameColor)
    : center_(center), width_(width), height_(height), fillColor_(fillColor),
      frameColor_(frameColor) {}

void Rectangle::draw() {
    // Calculate the coordinates of the rectangle's corners
    const float x1 = center_.x - width_ / 2;
    const float y1 = center_.y - height_ / 2;
    const float x2 = center_.x + width_ / 2;
    const float y2 = center_.y + height_ / 2;
    al_draw_filled_rectangle(x1, y1, x2, y2, fillColor_);
    al_draw_rectangle(x1, y1, x2, y2, frameColor_, 1);
}

// ### class Circle ###
Circle::Circle(Point center, float radius, ALLEGRO_COLOR fillColor,
               ALLEGRO_COLOR frameColor)
    : center_(center), radius_(radius), fillColor_(fillColor),
      frameColor_(frameColor) {}

void Circle::draw() {
    al_draw_filled_circle(center_.x, center_.y, radius_, fillColor_);
    al_draw_circle(center_.x, center_.y, radius_, frameColor_, 1);
}
