#include "brick.hpp"
#include "basic_brick.hpp"
#include "gold_brick.hpp"

#include <memory>

// factory method
std::shared_ptr<Brick> Brick::makeBrick(Color color, Point coord) {
    std::unique_ptr<Brick> ret;

    switch (color) {
    case Color::gold:
        ret = std::make_unique<GoldBrick>(coord);
        break;
    case Color::silver: // durability = 2 for silver
        ret = std::make_unique<BasicBrick>(color, coord, 2);
    default:
        ret = std::make_unique<BasicBrick>(color, coord, 1);
        break;
    }

    return ret;
}

// public constructor
Brick::Brick(Color color, Point coord, uint8_t durability)
    : durability_(durability), color_{color}, coord_{coord} {}

Brick::~Brick() = default;

void Brick::hit() { // this is default behavior
    if (durability_ > 0) {
        durability_--;
    }
}

unsigned Brick::getScore() const { return static_cast<unsigned>(color_); }
Point Brick::getCoordinate() const { return coord_; }
uint8_t Brick::getDurability() const { return durability_; }
bool Brick::isDestroyed() const { return durability_ == 0; }
