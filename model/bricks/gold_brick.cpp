#include "gold_brick.hpp"

GoldBrick::GoldBrick(Point coord) : Brick{Color::gold, coord} {}

void GoldBrick::hit() {} // Gold bricks are never destroyed
