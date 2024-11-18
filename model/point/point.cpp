#include "point.hpp"

#include <cstddef>

Point::Point(size_t x, size_t y) : x{x}, y{y} {}

bool Point::operator==(const Point &other) const {
    return x == other.x and y == other.y;
}
