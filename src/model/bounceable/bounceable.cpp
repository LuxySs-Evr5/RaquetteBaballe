#include "bounceable.hpp"
#include "../vec2/vec2.hpp"

#include <stdexcept>

std::string Bounceable::bounceTypeToString(Bounceable::BounceType bounceType) {
    switch (bounceType) {
    case Bounceable::BounceType::Vertical:
        return "Vertical";
        break;
    case Bounceable::BounceType::Horizontal:
        return "Horizontal";
        break;
    case Bounceable::BounceType::Corner:
        return "Corner";
        break;
    default:
        std::cerr << "Unknown BounceType" << std::endl;
        exit(-1);
    }
}

Bounceable::Bounceable(const Vec2 &center, double width, double height)
    : RectangleShape(center, width, height) {}

Bounceable::Bounceable(const Vec2 &topLeft, const Vec2 &bottomRight)
    : RectangleShape(topLeft, bottomRight) {}

Bounceable::~Bounceable() = default;

Bounceable::BounceType Bounceable::getBounceType(const Vec2 &point) const {
    if (point == getTopLeft() or point == getTopRight()
        or point == getBottomLeft() or point == getBottomRight()) {

        return BounceType::Corner;
    } else if (point.x == getLeft() or point.x == getRight()) {
        return BounceType::Vertical;
    } else if (point.y == getBottom() or point.y == getTop()) {
        return BounceType::Horizontal;
    } else {
        throw std::runtime_error{
            "point is not on a the Bounceable's perimeter"};
    }
}

Vec2 Bounceable::getDirVecAfterBounce(const Vec2 &closestPoint,
                                      const Vec2 &dirVec) const {
    BounceType bounceType = getBounceType(closestPoint);

    Vec2 ret = dirVec; // copy dirVec then change its components
    if (bounceType == BounceType::Horizontal) {
        ret.y = -ret.y;
    }
    if (bounceType == BounceType::Vertical) {
        ret.x = -ret.x;
    } else if (bounceType == BounceType::Corner) {
        ret.y = -ret.y;
        ret.x = -ret.x;
    }

    return ret;
}
