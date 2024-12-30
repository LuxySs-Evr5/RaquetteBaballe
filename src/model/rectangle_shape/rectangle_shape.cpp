#include "rectangle_shape.hpp"
#include "../vec2/vec2.hpp"

RectangleShape::RectangleShape(const Vec2 &center, double width, double height)
    : center_(center), width_{width}, height_{height} {}

RectangleShape::RectangleShape(const Vec2 &topLeft, const Vec2 &bottomRight)
    : center_{(Vec2{(topLeft.x + bottomRight.x) / 2,
                    (topLeft.y + bottomRight.y) / 2})},
      width_{std::abs(bottomRight.x - topLeft.x)},
      height_{std::abs(topLeft.y - bottomRight.y)} {}

void RectangleShape::setCenter(const Vec2 &centerPos) { center_ = centerPos; }

void RectangleShape::setWidth(double newWidth) { width_ = newWidth; }

void RectangleShape::setHeight(double newHeight) { height_ = newHeight; }

const Vec2 &RectangleShape::getCenter() const noexcept { return center_; }

double RectangleShape::getWidth() const noexcept { return width_; }

double RectangleShape::getHeight() const noexcept { return height_; }

double RectangleShape::getLeft() const noexcept {
    return center_.x - getWidth() / 2;
}

double RectangleShape::getRight() const noexcept {
    return center_.x + getWidth() / 2;
}

double RectangleShape::getBottom() const noexcept {
    return center_.y - getHeight() / 2;
}

double RectangleShape::getTop() const noexcept {
    return center_.y + getHeight() / 2;
}

Vec2 RectangleShape::getTopLeft() const noexcept {
    return Vec2{getLeft(), getTop()};
}

Vec2 RectangleShape::getTopRight() const noexcept {
    return Vec2{getRight(), getTop()};
}

Vec2 RectangleShape::getBottomLeft() const noexcept {
    return Vec2{getLeft(), getBottom()};
}

Vec2 RectangleShape::getBottomRight() const noexcept {
    return Vec2{getRight(), getBottom()};
}

bool RectangleShape::isOverlapping(const RectangleShape &other) {
    // X-axis check
    if (getRight() < other.getLeft() || other.getRight() < getLeft()) {
        return false;
    }

    // Y-axis check
    if (getTop() < other.getBottom() || other.getTop() < getBottom()) {
        return false;
    }

    return true;
}
