#ifndef GOLD_BRICK_HPP
#define GOLD_BRICK_HPP

#include "brick.hpp"

class GoldBrick final : public Brick {
  public:
    GoldBrick(BoundingBox boundingBox);

    virtual void hit() override; // Gold bricks are never destroyed
};

#endif
