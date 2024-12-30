#include "brick.hpp"
#include "basic_brick.hpp"
#include "gold_brick.hpp"
#include <memory>

Brick::Brick(const Vec2 &center, double width, double height, Color color,
             uint8_t durability, BonusType bonusType)
    : Bounceable{center, width, height}, color_{color}, durability_{durability},
      bonusType_(bonusType) {}

std::unique_ptr<Brick> Brick::makeBrick(const Vec2 &center, double width,
                                        double height, Color color,
                                        BonusType bonusType) {
    if (color == Color::gold) {
        return std::make_unique<GoldBrick>(center, width, height);
    } else if (color == Color::silver) {
        return std::make_unique<BasicBrick>(center, width, height, color,
                                            DURABILITY_SILVER_BRICK, bonusType);
    }
    return std::make_unique<BasicBrick>(center, width, height, color,
                                        DURABILITY_STANDARD_BRICK, bonusType);
}

Brick::~Brick() = default;

BonusType Brick::hit() { // this is default behavior
    if (durability_ > 0) {
        durability_--;
    }
    if (durability_ == 0) {
        return bonusType_;
    }
    return BonusType::None;
}

Color Brick::getColor() const { return color_; }

size_t Brick::getScore() const { return static_cast<unsigned>(color_); }

uint8_t Brick::getDurability() const { return durability_; }

bool Brick::isDestroyed() const { return durability_ == 0; }

BonusType Brick::getBonusType() const { return bonusType_; };

bool Brick::hasBonus() const { return bonusType_ != BonusType::None; }
