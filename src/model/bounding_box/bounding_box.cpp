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

void BoundingBox::setCenter(const Vec2 &centerPos) { center_ = centerPos; }

void BoundingBox::setWidth(double newWidth) { width_ = newWidth; }

void BoundingBox::setHeight(double newHeight) { height_ = newHeight; }

// #### Getters ####

Vec2 BoundingBox::getCenter() const noexcept { return center_; }

double BoundingBox::getWidth() const noexcept { return width_; }

double BoundingBox::getHeight() const noexcept { return height_; }

double BoundingBox::getLeft() const noexcept {
    return center_.x - getWidth() / 2;
}

double BoundingBox::getRight() const noexcept {
    return center_.x + getWidth() / 2;
}

double BoundingBox::getBottom() const noexcept {
    return center_.y - getHeight() / 2;
}

double BoundingBox::getTop() const noexcept {
    return center_.y + getHeight() / 2;
}

Vec2 BoundingBox::getTopLeft() const noexcept {
    return Vec2{getLeft(), getTop()};
}

Vec2 BoundingBox::getTopRight() const noexcept {
    return Vec2{getRight(), getTop()};
}

Vec2 BoundingBox::getBottomLeft() const noexcept {
    return Vec2{getLeft(), getBottom()};
}

Vec2 BoundingBox::getBottomRight() const noexcept {
    return Vec2{getRight(), getBottom()};
}

// #### Overlapping / Collision ####

bool BoundingBox::isOverlapping(const BoundingBox &other) {
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
