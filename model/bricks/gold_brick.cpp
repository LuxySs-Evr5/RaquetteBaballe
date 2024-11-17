#include "gold_brick.hpp"

GoldBrick::GoldBrick(Point topLeft, Point bottomRight)
    : Brick{Color::gold, topLeft, bottomRight} {}

void GoldBrick::hit() {} // Gold bricks are never destroyed
