#include "vec2.hpp"

#include <cmath>

Vec2::Vec2(int x, int y) : x{x}, y{y} {}

double Vec2::getModule() const {
    return std::sqrt(std::pow(abs(x), 2) + std::pow(abs(y), 2));
}

const Vec2 &Vec2::normalize() {
    double vecLength = getModule();

    x /= vecLength;
    y /= vecLength;

    return *this;
}
