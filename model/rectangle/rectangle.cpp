#include "rectangle.hpp"
#include "math.h"

Rectangle::Rectangle(Point center, size_t width, size_t height)
    : center_(center), width_{width}, height_{height} {}

Rectangle::~Rectangle() = default;

Point Rectangle::getCenter() const noexcept { return center_; }
size_t Rectangle::getWidth() const noexcept { return width_; }
size_t Rectangle::getHeight() const noexcept { return height_; }
