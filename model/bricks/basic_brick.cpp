#include "basic_brick.hpp"
#include "brick.hpp"

BasicBrick::BasicBrick(Color color, Point topLeft, Point bottomRight,
                       uint8_t durability)
    : Brick{color, topLeft, bottomRight, durability} {}
