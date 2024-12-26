#ifndef GOLD_BRICK_HPP
#define GOLD_BRICK_HPP

#include "brick.hpp"

class GoldBrick final : public Brick {
  public:
    GoldBrick(BoundingBox boundingBox);

    GoldBrick(const Brick &other); // In Level, we create a Brick, but when we past a gold brick to the gameboard, we need to convert it to a GoldBrick

    virtual BonusType hit() override; // Gold bricks are never destroyed
};

#endif
