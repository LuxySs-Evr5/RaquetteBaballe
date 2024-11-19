#include "brick.hpp"
#include "../rectangle/rectangle.hpp"
#include "basic_brick.hpp"
#include "gold_brick.hpp"

#include <memory>

// factory method
std::shared_ptr<Brick> Brick::makeBrick(Color color, Rectangle rectangle) {
    std::unique_ptr<Brick> ret;

    switch (color) {
    case Color::gold:
        ret = std::make_unique<GoldBrick>(rectangle);
        break;
    case Color::silver: // durability = 2 for silver
        ret = std::make_unique<BasicBrick>(color, rectangle,
                                           DURABILITY_SILVER_BRICK);
    default:
        ret = std::make_unique<BasicBrick>(color, rectangle,
                                           DURABILITY_STANDARD_BRICK);
        break;
    }

    return ret;
}

// protected constructor
Brick::Brick(Color color, Rectangle rectangle, uint8_t durability)
    : durability_(durability), color_{color}, rectangle_(rectangle) {}

Brick::~Brick() = default;

void Brick::hit() { // this is default behavior
    if (durability_ > 0) {
        durability_--;
    }
}

size_t Brick::getScore() const { return static_cast<unsigned>(color_); }
uint8_t Brick::getDurability() const { return durability_; }
const Rectangle &Brick::getRectangle() const { return rectangle_; }
bool Brick::isDestroyed() const { return durability_ == 0; }
