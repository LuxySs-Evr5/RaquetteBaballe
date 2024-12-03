#include "bounceable.hpp"
#include "../vec2/vec2.hpp"

#include <stdexcept>

Bounceable::Bounceable(Vec2 center, double width, double height)
    : boundingBox_(center, width, height) {}

Bounceable::Bounceable(Vec2 topLeft, Vec2 bottomRight)
    : boundingBox_(topLeft, bottomRight) {}

Bounceable::Bounceable(const BoundingBox &boundingBox)
    : boundingBox_(boundingBox) {}

Bounceable::~Bounceable() = default;

const BoundingBox &Bounceable::getBoundingBox() const { return boundingBox_; }

BounceType Bounceable::getBounceType(const Vec2 &point) const {
    if (point == boundingBox_.getTopLeft()
        or point == boundingBox_.getTopRight()
        or point == boundingBox_.getBottomLeft()
        or point == boundingBox_.getBottomRight()) {

        return BounceType::Corner;
    } else if (point.getX() == boundingBox_.getBottomRight().getX()
               or point.getX() == boundingBox_.getTopLeft().getX()) {
        return BounceType::Vertical;
    } else if (point.getY() == boundingBox_.getBottomRight().getY()
               or point.getY() == boundingBox_.getTopLeft().getY()) {
        return BounceType::Horizontal;
    } else {
        throw std::runtime_error{
            "point is not on a the Bounding Box's perimeter"};
    }
}

Vec2 Bounceable::getDirVecAfterBounce(const Vec2 &closestPoint,
                                      const Vec2 &dirVec) const {
    BounceType bounceType = getBounceType(closestPoint);

    Vec2 ret = dirVec; // copy dirVec then change its components
    if (bounceType == BounceType::Horizontal) {
        ret.setY(-ret.getY());
    }
    if (bounceType == BounceType::Vertical) {
        ret.setX(-ret.getX());
    } else if (bounceType == BounceType::Corner) {
        ret.setY(-ret.getY());
        ret.setX(-ret.getX());
    }

    return ret;
}
