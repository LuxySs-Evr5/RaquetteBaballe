#include "basic_brick.hpp"
#include "brick.hpp"

BasicBrick::BasicBrick(Color color, Point coord, uint8_t durability)
    : Brick{color, coord, durability} {}
