#include "vec2.hpp"

#include "../point/point.hpp"
#include <math.h>

Vec2::Vec2(Point point) : x(point.x), y(point.y) {}

Vec2::Vec2(double x, double y) : x{x}, y{y} {}

double Vec2::getModule() const {
    double xComponentLen = abs(x);
    double yComponentLen = abs(y);

    return std::sqrt(std::pow(xComponentLen, 2) + std::pow(yComponentLen, 2));
}

const Vec2 &Vec2::normalize() {
    double vecLength = getModule();

    x /= vecLength;
    y /= vecLength;

    return *this;
}

Point Vec2::toPoint() const { return Point(x, y); }
