#include "gold_brick.hpp"

GoldBrick::GoldBrick(BoundingBox boundingBox)
    : Brick{boundingBox, Color::gold, BonusType::None} {}

BonusType GoldBrick::hit() {
    // Gold bricks are never destroyed
    return BonusType::None;
}
