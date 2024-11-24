#include "bounceable.hpp"
#include "../vec2/vec2.hpp"

Bounceable::Bounceable(Vec2 center, double width, double height)
    : boundingBox_(center, width, height) {}

Bounceable::Bounceable(Vec2 topLeft, Vec2 bottomRight)
    : boundingBox_(topLeft, bottomRight) {}

const BoundingBox &Bounceable::getBoundingBox() const { return boundingBox_; }
