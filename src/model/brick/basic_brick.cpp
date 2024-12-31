#include "basic_brick.hpp"
#include "abstract_brick.hpp"

#include <memory>

BasicBrick::BasicBrick(const Vec2 &center, double width, double height,
                       Color color, uint8_t durability, BonusType bonusType)
    : AbstractBrick{center, width, height, color, durability, bonusType} {}

std::shared_ptr<AbstractBrick> BasicBrick::clone() {
    return std::static_pointer_cast<AbstractBrick>(
        std::make_shared<BasicBrick>(*this));
}
