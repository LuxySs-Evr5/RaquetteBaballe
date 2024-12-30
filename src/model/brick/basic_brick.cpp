#include "basic_brick.hpp"
#include "brick.hpp"

#include <memory>

BasicBrick::BasicBrick(const Vec2 &center, double width, double height,
                       Color color, uint8_t durability, BonusType bonusType)
    : Brick{center, width, height, color, durability, bonusType} {}

std::shared_ptr<Brick> BasicBrick::clone() {
    return std::static_pointer_cast<Brick>(std::make_shared<BasicBrick>(*this));
}
