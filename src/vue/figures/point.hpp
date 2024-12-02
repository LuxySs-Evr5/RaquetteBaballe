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

using namespace std;

struct Point {
  float x = 0, y = 0;

  Point(float valX, float valY);

  ~Point() = default;

  friend ostream &operator<<(ostream &os, const Point &point);
};

#endif // POINT_HPP