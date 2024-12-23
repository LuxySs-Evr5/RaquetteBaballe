#include "basic_brick.hpp"
#include "brick.hpp"

BasicBrick::BasicBrick(BoundingBox boundingBox, Color color, uint8_t durability,
                       BonusType bonusType)
    : Brick{boundingBox, color, durability, bonusType} {}
