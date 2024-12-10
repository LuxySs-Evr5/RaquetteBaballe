#include "basic_brick.hpp"
#include "brick.hpp"

BasicBrick::BasicBrick(Color color, BoundingBox boundingBox, uint8_t durability)
    : Brick{color, boundingBox, durability} {}
