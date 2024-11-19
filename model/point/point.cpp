#include "point.hpp"
#include "../vec2/vec2.hpp"

#include <iostream>

Point::Point(double x, double y) : x{x}, y{y} {}

bool Point::operator==(const Point &other) const {
    return x == other.x and y == other.y;
}

const Point Point::operator+(const Vec2 &vec) const {
    return Point{x + vec.x, y + vec.y};
}

const Point Point::operator+=(const Vec2 &vec) {
    x += vec.x;
    y += vec.y;
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Point &p) {
    os << "Point(" << p.x << ", " << p.y << ")";
    return os;
}
