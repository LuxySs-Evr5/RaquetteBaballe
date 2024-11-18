#include "rectangle.hpp"
#include "math.h"

Rectangle::Rectangle(Point topLeft, Point bottomRight)
    : topLeft_(topLeft), bottomRight_(bottomRight) {}

Point Rectangle::getTopLeft() const noexcept { return topLeft_; }

Point Rectangle::getBottomRight() const noexcept { return bottomRight_; }

Point Rectangle::getCenter() const noexcept {
    return Point{topLeft_.x + bottomRight_.x / 2,
                 topLeft_.y + bottomRight_.y / 2};
}
