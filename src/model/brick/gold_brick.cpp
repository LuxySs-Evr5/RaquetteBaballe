#include "gold_brick.hpp"

GoldBrick::GoldBrick(BoundingBox boundingBox)
    : Brick{boundingBox, Color::gold} {}

BonusType GoldBrick::hit() {
    return BonusType::None;
} // Gold bricks are never destroyed
