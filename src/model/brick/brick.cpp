#include "brick.hpp"
#include "../bounding_box/bounding_box.hpp"
#include "basic_brick.hpp"
#include "gold_brick.hpp"

#include <memory>

// factory method
std::shared_ptr<Brick> Brick::makeBrick(Color color, BoundingBox boundingBox) {
    std::unique_ptr<Brick> ret;

    switch (color) {
    case Color::gold:
        ret = std::make_unique<GoldBrick>(boundingBox);
        break;
    case Color::silver: // durability = 2 for silver
        ret = std::make_unique<BasicBrick>(color, boundingBox,
                                           DURABILITY_SILVER_BRICK);
    default:
        ret = std::make_unique<BasicBrick>(color, boundingBox,
                                           DURABILITY_STANDARD_BRICK);
        break;
    }

    return ret;
}

// protected constructor
Brick::Brick(Color color, const BoundingBox &boundingBox, uint8_t durability)
    : color_{color}, Bounceable(boundingBox), durability_(durability) {}

Brick::~Brick() = default;

void Brick::hit() { // this is default behavior
    if (durability_ > 0) {
        durability_--;
    }
}

size_t Brick::getScore() const { return static_cast<unsigned>(color_); }
uint8_t Brick::getDurability() const { return durability_; }
bool Brick::isDestroyed() const { return durability_ == 0; }
