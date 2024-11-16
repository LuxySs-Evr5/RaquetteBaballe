/**
 * @file circle.hpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Define the Circle class
 * @date 16/11/2024
 *
 */

#include "circle.hpp"
#include "point.hpp"
#include <allegro5/allegro_primitives.h>

// ### Constructors ###

Circle::Circle(Point center, float radius, ALLEGRO_COLOR color)
    : center_(center), radius_(radius), color_(color) {}


// ### Destructor ###

Circle::~Circle() = default;


// ### Public Methods ###

void Circle::draw() {
  al_draw_filled_circle(center_.x, center_.y, radius_, color_);
  al_draw_circle(center_.x, center_.y, radius_, color_, 1);
}


// ### Setters ###

void Circle::setCenter(const Point center) { center_ = center; }

void Circle::setRadius(const float radius) { radius_ = radius; }

void Circle::setColor(const ALLEGRO_COLOR &color) { color_ = color; }


// ### Getters ###

Point Circle::getCenter() const { return center_; }

float Circle::getRadius() const { return radius_; }

ALLEGRO_COLOR Circle::getColor() const { return color_; }