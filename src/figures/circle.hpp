/**
 * @file circle.hpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Define the Circle class
 * @date 16/11/2024
 *
 */

#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "point.hpp"
#include "../colors/colors.hpp"

class Circle {
private:
  Point center_;
  float radius_;
  ALLEGRO_COLOR color_;

public:
  Circle(Point center, float radius, ALLEGRO_COLOR color = COLOR_BLACK);

  ~Circle();

  void draw();

  void setCenter(const Point center);
  void setRadius(const float radius);
  void setColor(const ALLEGRO_COLOR &color);

  Point getCenter() const;
  float getRadius() const;
  ALLEGRO_COLOR getColor() const;
  
};

#endif // CIRCLE_HPP