#include "rectangle.hpp"
#include "../point/point.hpp"
#include "math.h"

Rectangle::Rectangle(Point center, double width, double height)
    : center_(center), width_{width}, height_{height} {}

Rectangle::Rectangle(Point topLeft, Point bottomRight)
    : center_{(Point{(topLeft.x + bottomRight.x) / 2,
                     (topLeft.y + bottomRight.y) / 2})},
      width_{std::abs(bottomRight.x - topLeft.x)},
      height_{std::abs(topLeft.y - bottomRight.y)} {}

Rectangle::~Rectangle() = default;

Point Rectangle::getCenter() const noexcept { return center_; }

double Rectangle::getWidth() const noexcept { return width_; }

double Rectangle::getHeight() const noexcept { return height_; }

Point Rectangle::getTopLeft() const noexcept {
    return Point{
        center_.x - width_ / 2,
        center_.y - height_ / 2,
    };
}

Point Rectangle::getBottomRight() const noexcept {
    return Point{
        center_.x + width_ / 2,
        center_.y + height_ / 2,
    };
}
