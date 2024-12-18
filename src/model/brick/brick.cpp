#include "brick.hpp"
#include "../bounding_box/bounding_box.hpp"
#include "basic_brick.hpp"
#include "gold_brick.hpp"

#include <memory>

// #### Protected Constructor ####

Brick::Brick(const BoundingBox &boundingBox, Color color, uint8_t durability)
    : Bounceable{boundingBox}, color_{color}, durability_{durability} {}

// #### Factory ####

std::unique_ptr<Brick> Brick::makeBrick(Color color, BoundingBox boundingBox) {

    if (color == Color::gold) {
        return std::make_unique<GoldBrick>(boundingBox);
    } else if (color == Color::silver) {
        return std::make_unique<BasicBrick>(boundingBox, color,
                                            DURABILITY_SILVER_BRICK);
    }
    return std::make_unique<BasicBrick>(boundingBox, color,
                                        DURABILITY_STANDARD_BRICK);
}

Brick::~Brick() = default;

// #### Brick Actions ####

void Brick::hit() { // this is default behavior
    if (durability_ > 0) {
        durability_--;
    }
}

// #### Getters ####

Color Brick::getColor() const { return color_; }

size_t Brick::getScore() const { return static_cast<unsigned>(color_); }

uint8_t Brick::getDurability() const { return durability_; }

bool Brick::isDestroyed() const { return durability_ == 0; }
