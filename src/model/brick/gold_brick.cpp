#include "gold_brick.hpp"

GoldBrick::GoldBrick(BoundingBox boundingBox)
    : Brick{boundingBox, Color::gold} {}

void GoldBrick::hit() {} // Gold bricks are never destroyed
