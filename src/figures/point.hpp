/**
 * @file point.hpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Definition of the Point struct
 * @date 16/11/2024
 *
 */

#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>

struct Point {
  float x = 0, y = 0;

  Point(float x, float y) : x(x), y(y) {}

  ~Point() = default;

  float getX() const { return x; }

  float getY() const { return y; }

  friend std::ostream &operator<<(std::ostream &os, const Point &point) {
    os << "(" << point.x << ", " << point.y << ")";
    return os;
  }
};

#endif // POINT_HPP