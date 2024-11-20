#include "bounding_box.hpp"
#include "../vec2/vec2.hpp"
#include <stdexcept>

BoundingBox::BoundingBox(Vec2 center, double width, double height)
    : center_(center), width_{width}, height_{height} {}

BoundingBox::BoundingBox(Vec2 topLeft, Vec2 bottomRight)
    : center_{(Vec2{(topLeft.x + bottomRight.x) / 2,
                    (topLeft.y + bottomRight.y) / 2})},
      width_{std::abs(bottomRight.x - topLeft.x)},
      height_{std::abs(topLeft.y - bottomRight.y)} {}

BoundingBox::~BoundingBox() = default;

Vec2 BoundingBox::getCenter() const noexcept { return center_; }

double BoundingBox::getWidth() const noexcept { return width_; }

double BoundingBox::getHeight() const noexcept { return height_; }

Vec2 BoundingBox::getTopLeft() const noexcept {
    return Vec2{
        center_.x - width_ / 2,
        center_.y - height_ / 2,
    };
}

Vec2 BoundingBox::getBottomRight() const noexcept {
    return Vec2{
        center_.x + width_ / 2,
        center_.y + height_ / 2,
    };
}

BoundingBoxPosition BoundingBox::getPointPosition(const Vec2 &point) const {
    if (point == getTopLeft()) {
        return BoundingBoxCorner::TopLeft;

    } else if (point == getTopLeft()) {
        return BoundingBoxCorner::BottomLeft;

    } else if (point == getBottomRight()) {
        return BoundingBoxCorner::TopRight;

    } else if (point == getBottomRight()) {
        return BoundingBoxCorner::BottomRight;

    } else if (point.x == getBottomRight().x) {
        return BoundingBoxEdge::Right;

    } else if (point.x == getTopLeft().x) {
        return BoundingBoxEdge::Left;

    } else if (point.y == getTopLeft().y) {
        return BoundingBoxEdge::Up;

    } else if (point.y == getBottomRight().y) {
        return BoundingBoxEdge::Down;

    } else {
        throw std::runtime_error{
            "point is not on a the Bounding Box's perimeter"};
    }
}
