/**
 * @file point.hpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Definition of the Point struct
 * @date 16/11/2024
 *
 */

#ifndef POINT_HPP
#define POINT_HPP

struct Point {
  float x = 0, y = 0;
  Point(float x, float y) : x(x), y(y) {}
  ~Point() = default;
};

#endif // POINT_HPP