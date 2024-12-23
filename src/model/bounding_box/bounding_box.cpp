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

// #### Setters ####

void BoundingBox::setCenter(Vec2 coordinate) { center_ = coordinate; }

void BoundingBox::setWidth(double newWidth) { width_ = newWidth; }

void BoundingBox::setHeight(double newHeight) { height_ = newHeight; }

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

// #### Overlapping / Collision ####

bool BoundingBox::isOverlapping(const BoundingBox &other) {
    Vec2 topLeft1 = getTopLeft();
    Vec2 bottomRight1 = getBottomRight();

    Vec2 topLeft2 = other.getTopLeft();
    Vec2 bottomRight2 = other.getBottomRight();

    if (bottomRight1.x < topLeft2.x || bottomRight2.x < topLeft1.x) {
        return false;
    }

    if (bottomRight1.y < topLeft2.y || bottomRight2.y < topLeft1.y) {
        return false;
    }

    return true;
}
