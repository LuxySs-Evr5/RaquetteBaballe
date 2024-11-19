#include "rectangle.hpp"
#include "../vec2/vec2.hpp"
#include "math.h"

Rectangle::Rectangle(Vec2 center, double width, double height)
    : center_(center), width_{width}, height_{height} {}

Rectangle::Rectangle(Vec2 topLeft, Vec2 bottomRight)
    : center_{(Vec2{(topLeft.x + bottomRight.x) / 2,
                    (topLeft.y + bottomRight.y) / 2})},
      width_{std::abs(bottomRight.x - topLeft.x)},
      height_{std::abs(topLeft.y - bottomRight.y)} {}

Rectangle::~Rectangle() = default;

Vec2 Rectangle::getCenter() const noexcept { return center_; }

double Rectangle::getWidth() const noexcept { return width_; }

double Rectangle::getHeight() const noexcept { return height_; }

Vec2 Rectangle::getTopLeft() const noexcept {
    return Vec2{
        center_.x - width_ / 2,
        center_.y - height_ / 2,
    };
}

Vec2 Rectangle::getBottomRight() const noexcept {
    return Vec2{
        center_.x + width_ / 2,
        center_.y + height_ / 2,
    };
}
