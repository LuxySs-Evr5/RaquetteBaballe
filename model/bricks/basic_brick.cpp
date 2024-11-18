#include "basic_brick.hpp"
#include "brick.hpp"

BasicBrick::BasicBrick(Color color, Rectangle rectangle, uint8_t durability)
    : Brick{color, rectangle, durability} {}
