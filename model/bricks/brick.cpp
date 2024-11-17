#include "brick.hpp"
#include "basic_brick.hpp"
#include "gold_brick.hpp"

#include <memory>

// factory method
std::shared_ptr<Brick> Brick::makeBrick(Color color, Point topLeft,
                                        Point bottomRight) {
    std::unique_ptr<Brick> ret;

    switch (color) {
    case Color::gold:
        ret = std::make_unique<GoldBrick>(topLeft, bottomRight);
        break;
    case Color::silver: // durability = 2 for silver
        ret = std::make_unique<BasicBrick>(color, topLeft, bottomRight, 2);
    default:
        ret = std::make_unique<BasicBrick>(color, topLeft, bottomRight, 1);
        break;
    }

    return ret;
}

// public constructor
Brick::Brick(Color color, Point topLeft, Point bottomRight, uint8_t durability)
    : durability_(durability), color_{color}, topLeft_{topLeft},
      bottomRight_{bottomRight} {}

Brick::~Brick() = default;

Point Brick::getNearestPointFrom(Point point) const {
    double nearestX = std::max(topLeft_.x, std::min(bottomRight_.x, point.x));
    double nearestY = std::max(bottomRight_.y, std::min(topLeft_.y, point.y));
    return Point{nearestX, nearestY};
}

void Brick::hit() { // this is default behavior
    if (durability_ > 0) {
        durability_--;
    }
}

unsigned Brick::getScore() const { return static_cast<unsigned>(color_); }
uint8_t Brick::getDurability() const { return durability_; }
bool Brick::isDestroyed() const { return durability_ == 0; }
