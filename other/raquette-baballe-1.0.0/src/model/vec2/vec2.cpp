#include "vec2.hpp"

#include <cmath>
#include <ostream>
#include <sstream>

/**
 * Helper function.
 * Returns a clamped a value within the specified range.
 *
 * @param value The value to clamp.
 * @param min The lower bound of the range.
 * @param max The upper bound of the range.
 */
double clampedNum(double value, double min, double max) {
    return std::max(min, std::min(max, value));
}

Vec2::Vec2() : x{0}, y{0} {}

Vec2::Vec2(double xComponent, double yComponent)
    : x{xComponent}, y{yComponent} {}

double Vec2::getModule() const {
    return std::sqrt(std::pow(x, 2) + std::pow(y, 2));
}

const Vec2 &Vec2::normalize() {
    double vecLength = getModule();

    x /= vecLength;
    y /= vecLength;

    return *this;
}

Vec2 Vec2::normalized() const {
    Vec2 copy = *this;
    return copy.normalize();
}

Vec2 Vec2::clamped(const Vec2 &min, const Vec2 &max) const {
    return Vec2{clampedNum(x, min.x, max.x), clampedNum(y, min.y, max.y)};
}

bool Vec2::operator==(const Vec2 &other) const {
    return static_cast<int>(x) == static_cast<int>(other.x)
           && static_cast<int>(y) == static_cast<int>(other.y);
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

Vec2::operator Point() const {
    return Point{static_cast<float>(x), static_cast<float>(y)};
}

Vec2::operator std::string() const {
    std::ostringstream oss;
    oss << "(" << x << ", " << y << ")";
    return oss.str();
}

std::ostream &operator<<(std::ostream &os, const Vec2 &vec) {
    os << "Vec2(" << vec.x << ", " << vec.y << ")";
    return os;
}
