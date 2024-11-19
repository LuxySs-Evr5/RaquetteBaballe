#include "vec2.hpp"

#include <cmath>

Vec2::Vec2(double x, double y) : x{x}, y{y} {}

double Vec2::getModule() const {
    return std::sqrt(std::pow(x, 2) + std::pow(y, 2));
}

const Vec2 &Vec2::normalize() {
    double vecLength = getModule();

    x /= vecLength;
    y /= vecLength;

    return *this;
}

const Vec2 Vec2::operator*(double scalar) const {
    return Vec2(x * scalar, y * scalar);
}

std::ostream &operator<<(std::ostream &os, const Vec2 &vec) {
    os << "Vec2(" << vec.x << ", " << vec.y << ")";
    return os;
}
