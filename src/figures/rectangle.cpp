/**
 * @file rectangle.hpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Define the Rectangle class
 * @date 16/11/2024
 *
 */

#include "rectangle.hpp"
#include <allegro5/allegro_primitives.h>


// ### Constructor ###

Rectangle::Rectangle(Point center, float width, float height,
                     ALLEGRO_COLOR color)
    : center_(center), width_(width), height_(height), color_(color) {}


// ### Destructor ###

Rectangle::~Rectangle() = default;


// ### Public Methods ###

void Rectangle::draw() {
  const float x1 = center_.x - width_ / 2;
  const float y1 = center_.y - height_ / 2;
  const float x2 = center_.x + width_ / 2;
  const float y2 = center_.y + height_ / 2;
  al_draw_filled_rectangle(x1, y1, x2, y2, color_);
  al_draw_rectangle(x1, y1, x2, y2, color_, 1);
}


// ### Setters ###

void Rectangle::setColor(const ALLEGRO_COLOR &color) { color_ = color; }

void Rectangle::setCenter(const Point center) { center_ = center; }

void Rectangle::setWidth(const float width) { width_ = width; }

void Rectangle::setHeight(const float height) { height_ = height; }


// ### Getters ###

Point Rectangle::getCenter() const { return center_; }

float Rectangle::getWidth() const { return width_; }

float Rectangle::getHeight() const { return height_; }

ALLEGRO_COLOR Rectangle::getColor() const { return color_; }
