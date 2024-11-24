/**
 * @file forme.cpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Define the class parent Forme and the class fille Circle and Rectangle
 * @date 16/11/2024
 *
 */

#include <allegro5/allegro_primitives.h>
#include <iostream>
#include "forme.hpp"

// ### class Forme ###
// # Constructors #
Forme::Forme(Point center, ALLEGRO_COLOR color)
    : center_(center), color_(color) {}

// # Getters #
Point Forme::getCenter() const { return center_; }

ALLEGRO_COLOR Forme::getColor() const { return color_; }

// # Setters #
void Forme::setCenter(const Point center) { center_ = center; }

void Forme::setColor(const ALLEGRO_COLOR &color) { color_ = color; }

// # Public Methods #
void Forme::move(const float x, const float y) {
  center_.x += x;
  center_.y += y;
}


// ### class Rectangle ###
// # Constructors #
Rectangle::Rectangle(Point center, float width, float height, ALLEGRO_COLOR color)
    : Forme(center, color), width_(width), height_(height) {}

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

void Rectangle::moveHorizontally(float x) {
  center_.x += x;
}

// ### class Circle ###
// # Constructors #
Circle::Circle(Point center, float radius, ALLEGRO_COLOR color)
    : Forme(center, color), radius_(radius) {}

// # Getters #
float Circle::getRadius() const { return radius_; }

// # Setters #
void Circle::setSpeedX(const float speedX) { speedX_ = speedX; }

void Circle::setSpeedY(const float speedY) { speedY_ = speedY; }

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