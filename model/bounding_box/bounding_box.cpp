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
        center_.y + height_ / 2,
    };
}

Vec2 BoundingBox::getBottomRight() const noexcept {
    return Vec2{
        center_.x + width_ / 2,
        center_.y - height_ / 2,
    };
}

Vec2 BoundingBox::getTopRight() const noexcept {
    return Vec2{
        center_.x + width_ / 2,
        center_.y + height_ / 2,
    };
}
Vec2 BoundingBox::getBottomLeft() const noexcept {
    return Vec2{
        center_.x - width_ / 2,
        center_.y - height_ / 2,
    };
}

BounceType BoundingBox::getBounceType(const Vec2 &point) const {
    if (point == getTopLeft() or point == getTopRight()
        or point == getBottomLeft() or point == getBottomRight()) {

        return BounceType::Corner;
    } else if (point.x == getBottomRight().x || point.x == getTopLeft().x) {
        return BounceType::Vertical;
    } else if (point.y == getBottomRight().y || point.y == getTopLeft().y) {
        return BounceType::Horizontal;
    } else {
        throw std::runtime_error{
            "point is not on a the Bounding Box's perimeter"};
    }
}
