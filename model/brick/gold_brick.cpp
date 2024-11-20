#include "gold_brick.hpp"

GoldBrick::GoldBrick(BoundingBox boundingBox)
    : Brick{Color::gold, boundingBox} {}

void GoldBrick::hit() {} // Gold bricks are never destroyed
