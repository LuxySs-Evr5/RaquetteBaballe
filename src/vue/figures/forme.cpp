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
// # Constructors #
Rectangle::Rectangle(Point center, float width, float height, Color color)
    : center_(center), width_(width), height_(height) {
    color_ = colorToAllegroColor(color);
}

// # Getters #
float Rectangle::getWidth() const { return width_; }

float Rectangle::getHeight() const { return height_; }

// # Setters #
void Rectangle::setWidth(const float width) { width_ = width; }

void Rectangle::setHeight(const float height) { height_ = height; }

// # Public Methods #
void Rectangle::draw() {
    const float x1 = center_.x - width_ / 2;
    const float y1 = center_.y - height_ / 2;
    const float x2 = center_.x + width_ / 2;
    const float y2 = center_.y + height_ / 2;
    al_draw_filled_rectangle(x1, y1, x2, y2, color_);
    al_draw_rectangle(x1, y1, x2, y2, color_, 1);
}

void Rectangle::moveHorizontally(float x) { center_.x += x; }

// ### class Circle ###
// # Constructors #
Circle::Circle(Point center, float radius, ALLEGRO_COLOR color)
    : center_(center), radius_(radius), color_(color) {}

// # Getters #
float Circle::getRadius() const { return radius_; }

// # Setters #
void Circle::setRadius(const float radius) { radius_ = radius; }

// # Public Methods #
void Circle::draw() {
    al_draw_filled_circle(center_.x, center_.y, radius_, color_);
    al_draw_circle(center_.x, center_.y, radius_, color_, 1);
}

void Circle::move(const float x, const float y) {
    center_.x += x;
    center_.y += y;
}
