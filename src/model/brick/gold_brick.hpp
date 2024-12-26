#ifndef GOLD_BRICK_HPP
#define GOLD_BRICK_HPP

#include "brick.hpp"

/**
 * @brief Represents a golden brick.
 */
class GoldBrick final : public Brick {
  public:
    /**
     * @brief Constructs a new GoldBrick.
     * @param boudingBox The BoudingBox.
     */
    GoldBrick(BoundingBox boundingBox);

    virtual ~GoldBrick() = default;

    /**
     * @brief Hit the golden brick (doesn't have any effect).
     */
    virtual BonusType hit() override; // Gold bricks are never destroyed
};

#endif
