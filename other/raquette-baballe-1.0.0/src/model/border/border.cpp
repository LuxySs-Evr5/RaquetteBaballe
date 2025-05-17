#include "border.hpp"

Border::Border(const Vec2 &center, double width, double height)
    : Bounceable(center, width, height) {}

Border::Border(const Vec2 &topLeft, const Vec2 &bottomRight)
    : Bounceable(topLeft, bottomRight) {}
