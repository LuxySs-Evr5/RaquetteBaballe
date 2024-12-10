#include "vec2.hpp"

#include <cmath>
#include <ostream>

Vec2::Vec2() : x{0}, y{0} {}
Vec2::Vec2(double x, double y) : x{x}, y{y} {}

double Vec2::getModule() const {
    std::cout << "power : " << std::pow(x, 2) << std::endl;
    return std::sqrt(std::pow(x, 2) + std::pow(y, 2));
}

const Vec2 &Vec2::normalize() {
    double vecLength = getModule();

    x /= vecLength;
    y /= vecLength;

    return *this;
}

double clamp(double value, double min, double max) {
    return std::max(min, std::min(max, value));
}

Vec2 Vec2::clamped(const Vec2 &min, const Vec2 &max) const {
    return Vec2{clamp(x, min.x, max.x), clamp(y, min.y, max.y)};
}

bool Vec2::operator==(const Vec2 &other) const {
    return x == other.x && y == other.y;
}

Vec2 Vec2::operator+(const Vec2 &vec) const { return Vec2{x, y} += vec; }

Vec2 &Vec2::operator+=(const Vec2 &vec) {
    x += vec.x;
    y += vec.y;
    return *this;
}

Vec2 Vec2::operator-(const Vec2 &vec) const { return Vec2{x, y} -= vec; }

Vec2 &Vec2::operator-=(const Vec2 &vec) {
    x -= vec.x;
    y -= vec.y;
    return *this;
}

Vec2 Vec2::operator-() const { return Vec2{-x, -y}; }

Vec2 Vec2::operator*(double scalar) const { return Vec2{x, y} *= scalar; }

Vec2 &Vec2::operator*=(double scalar) {
    x *= scalar;
    y *= scalar;
    return *this;
}

Point Vec2::toPoint() const {
    return Point{static_cast<float>(x), static_cast<float>(y)};
}

std::ostream &operator<<(std::ostream &os, const Vec2 &vec) {
    os << "Vec2(" << vec.x << ", " << vec.y << ")";
    return os;
}
