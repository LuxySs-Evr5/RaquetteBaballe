#include "bounding_box.hpp"
#include "../vec2/vec2.hpp"

// #### Constructors ####

BoundingBox::BoundingBox(Vec2 center, double width, double height)
    : center_(center), width_{width}, height_{height} {}

BoundingBox::BoundingBox(Vec2 topLeft, Vec2 bottomRight)
    : center_{(Vec2{(topLeft.x + bottomRight.x) / 2,
                    (topLeft.y + bottomRight.y) / 2})},
      width_{std::abs(bottomRight.x - topLeft.x)},
      height_{std::abs(topLeft.y - bottomRight.y)} {}

// #### Destructor ####

BoundingBox::~BoundingBox() = default;

void BoundingBox::setCenter(Vec2 coordinate) { center_ = coordinate; }

// #### Getters ####

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
