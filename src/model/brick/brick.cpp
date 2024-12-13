#include "brick.hpp"
#include "../bounding_box/bounding_box.hpp"
#include "basic_brick.hpp"
#include "gold_brick.hpp"

#include <memory>

// factory method
std::unique_ptr<Brick> Brick::makeBrick(Color color, BoundingBox boundingBox) {
    std::unique_ptr<Brick> ret;

    switch (color) {
    case Color::gold:
        ret = std::make_unique<GoldBrick>(boundingBox);
        break;
    case Color::silver: // durability = 2 for silver
        ret = std::make_unique<BasicBrick>(boundingBox, color,
                                           DURABILITY_SILVER_BRICK);
        break;
    default:
        ret = std::make_unique<BasicBrick>(boundingBox, color,
                                           DURABILITY_STANDARD_BRICK);
        break;
    }

    return ret;
}

// protected constructor
Brick::Brick(const BoundingBox &boundingBox, Color color, uint8_t durability)
    : Bounceable{boundingBox}, color_{color}, durability_{durability} {}

Brick::~Brick() = default;

void Brick::hit() { // this is default behavior
    if (durability_ > 0) {
        durability_--;
    }
}

size_t Brick::getScore() const { return static_cast<unsigned>(color_); }
uint8_t Brick::getDurability() const { return durability_; }
bool Brick::isDestroyed() const { return durability_ == 0; }

Color Brick::getColor() const { return color_; }
