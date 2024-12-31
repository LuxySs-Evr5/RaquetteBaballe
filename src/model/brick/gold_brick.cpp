#include "gold_brick.hpp"

GoldBrick::GoldBrick(const Vec2 &center, double width, double height)
    : AbstractBrick{center, width, height, Color::gold} {}

BonusType GoldBrick::hit() {
    // Gold bricks are never destroyed
    return BonusType::None;
}

std::shared_ptr<AbstractBrick> GoldBrick::clone() {
    return std::static_pointer_cast<AbstractBrick>(
        std::make_shared<GoldBrick>(*this));
}
