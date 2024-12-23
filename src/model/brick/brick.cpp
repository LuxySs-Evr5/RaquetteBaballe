#include "brick.hpp"
#include "../bounding_box/bounding_box.hpp"
#include "gold_brick.hpp"

#include <memory>

// #### Protected Constructor ####

Brick::Brick(const BoundingBox &boundingBox, Color color, uint8_t durability,
             BonusType bonusType)
    : Bounceable{boundingBox}, color_{color}, durability_{durability},
      bonusType_(bonusType) {}

// #### Factory ####

std::unique_ptr<Brick> Brick::makeBrick(Color color, BoundingBox boundingBox,
                                        BonusType bonusType) {

    if (color == Color::gold) {
        return std::make_unique<GoldBrick>(boundingBox);
    } else if (color == Color::silver) {
        return std::make_unique<Brick>(boundingBox, color,
                                       DURABILITY_SILVER_BRICK, bonusType);
    }
    return std::make_unique<Brick>(boundingBox, color,
                                   DURABILITY_STANDARD_BRICK, bonusType);
}

Brick::~Brick() = default;

// #### Brick Actions ####

BonusType Brick::hit() { // this is default behavior
    if (durability_ > 0) {
        durability_--;
    }
    if (durability_ == 0) {
        return bonusType_;
    }
    return BonusType::None;
}

// #### Getters ####

Color Brick::getColor() const { return color_; }

size_t Brick::getScore() const { return static_cast<unsigned>(color_); }

uint8_t Brick::getDurability() const { return durability_; }

bool Brick::isDestroyed() const { return durability_ == 0; }
