#include "point.hpp"

Point::Point(double x, double y) : x{x}, y{y} {}

bool Point::operator==(const Point &other) const {
    return x == other.x and y == other.y;
}
