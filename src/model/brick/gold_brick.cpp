#include "gold_brick.hpp"

GoldBrick::GoldBrick(BoundingBox boundingBox)
    : Brick{boundingBox, Color::gold} {}

GoldBrick::GoldBrick(const Brick &other) : Brick{other} {}

BonusType GoldBrick::hit() {
    // Gold bricks are never destroyed
    return BonusType::None;
}
