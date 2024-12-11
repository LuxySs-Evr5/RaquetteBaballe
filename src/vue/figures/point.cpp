/**
 * @file point.hpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Definition of the Point struct
 * @date 16/11/2024
 *
 */

#include "point.hpp"

// ### Constructors ###
Point::Point(float valX, float valY) : x(valX), y(valY) {}

// ### Overloaded operators ###
ostream &operator<<(ostream &os, const Point &point) {
    os << "(" << point.x << ", " << point.y << ")";
    return os;
}
