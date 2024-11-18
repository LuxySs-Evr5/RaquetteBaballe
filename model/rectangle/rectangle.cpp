#include "rectangle.hpp"

Rectangle::Rectangle(Point topLeft, Point bottomRight);

Point Rectangle::getTopLeft() const noexcept { return topLeft_; }

Point Rectangle::getBottomRight() const noexcept { return bottomRight_; }

Point Rectangle::getCenter() const noexcept {
    return Point {
        (topLeft_.x + bottomRight_.x / 2, topLeft_.y + bottomRight_.y / 2, )
    }
}

bool Rectangle::edgeContains(Point p) const {
    return ((p.x == topLeft_.x or p.x == bottomRight_.x)
            and (p.y == topLeft_.y or p.y == bottomRight_.y))
}
