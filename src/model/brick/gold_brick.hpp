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
    GoldBrick(const GoldBrick &) = default;
    GoldBrick(GoldBrick &&) = default;

    GoldBrick &operator=(const GoldBrick &) = default;
    GoldBrick &operator=(GoldBrick &&) = default;

    virtual ~GoldBrick() = default;

    /**
     * @brief Hit the golden brick (doesn't have any effect).
     */
    virtual BonusType hit() override; // Gold bricks are never destroyed
};

#endif
