#include "gold_brick.hpp"

GoldBrick::GoldBrick(const Vec2 &center, double width, double height)
    : Brick{center, width, height, Color::gold} {}

BonusType GoldBrick::hit() {
    // Gold bricks are never destroyed
    return BonusType::None;
}

std::shared_ptr<Brick> GoldBrick::clone() {
    return std::static_pointer_cast<Brick>(std::make_shared<GoldBrick>(*this));
}
