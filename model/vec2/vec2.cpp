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

bool Vec2::operator==(const Vec2 &other) const {
    return x == other.x && y == other.y;
}

const Vec2 Vec2::operator+(const Vec2 &vec) const { return Vec2{x, y} += vec; }

const Vec2 Vec2::operator+=(const Vec2 &vec) {
    x += vec.x;
    y += vec.y;
    return *this;
}

const Vec2 Vec2::operator-(const Vec2 &vec) const { return Vec2{x, y} -= vec; }

const Vec2 Vec2::operator-=(const Vec2 &vec) {
    x -= vec.x;
    y -= vec.y;
    return *this;
}

const Vec2 Vec2::operator*(double scalar) const { return Vec2{x, y} *= scalar; }

const Vec2 Vec2::operator*=(double scalar) {
    x *= scalar;
    y *= scalar;
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Vec2 &vec) {
    os << "Vec2(" << vec.x << ", " << vec.y << ")";
    return os;
}
