#include "gold_brick.hpp"

GoldBrick::GoldBrick(Rectangle rectangle) : Brick{Color::gold, rectangle} {}

void GoldBrick::hit() {} // Gold bricks are never destroyed
