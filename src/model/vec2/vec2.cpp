#include "vec2.hpp"

#include <cmath>
#include <ostream>

Vec2::Vec2() : x_{0}, y_{0} {}
Vec2::Vec2(double x, double y) : x_{x}, y_{y} {}

double Vec2::getModule() const {
    std::cout << "power : " << std::pow(x_, 2) << std::endl;
    return std::sqrt(std::pow(x_, 2) + std::pow(y_, 2));
}

double Vec2::getX() const noexcept { return x_; }
Vec2::getY() const noexcept { return y_; }

void Vec2::setX(double x) { x_ = x; }
void Vec2::setY(double y) { y_ = y; };

const Vec2 &Vec2::normalize() {
    double vecLength = getModule();

    x_ /= vecLength;
    y_ /= vecLength;

    return *this;
}

double clamp(double value, double min, double max) {
    return std::max(min, std::min(max, value));
}

Vec2 Vec2::clamped(const Vec2 &min, const Vec2 &max) const {
    return Vec2{clamp(x_, min.x_, max.x_), clamp(y_, min.y_, max.y_)};
}

bool Vec2::operator==(const Vec2 &other) const {
    return x_ == other.x_ && y_ == other.y_;
}

Vec2 Vec2::operator+(const Vec2 &vec) const { return Vec2{x_, y_} += vec; }

Vec2 &Vec2::operator+=(const Vec2 &vec) {
    x_ += vec.x_;
    y_ += vec.y_;
    return *this;
}

Vec2 Vec2::operator-(const Vec2 &vec) const { return Vec2{x_, y_} -= vec; }

Vec2 &Vec2::operator-=(const Vec2 &vec) {
    x_ -= vec.x_;
    y_ -= vec.y_;
    return *this;
}

Vec2 Vec2::operator-() const { return Vec2{-x_, -y_}; }

Vec2 Vec2::operator*(double scalar) const { return Vec2{x_, y_} *= scalar; }

Vec2 &Vec2::operator*=(double scalar) {
    x_ *= scalar;
    y_ *= scalar;
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Vec2 &vec) {
    os << "Vec2(" << vec.x_ << ", " << vec.y_ << ")";
    return os;
}
