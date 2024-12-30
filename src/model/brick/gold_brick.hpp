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
     * @param center The brick's center.
     * @param width The brick's width.
     * @param height The brick's height.
     */
    GoldBrick(const Vec2 &center, double width, double height);

    virtual ~GoldBrick() = default;

    /**
     * @brief Hit the golden brick (doesn't have any effect).
     */
    virtual BonusType hit() override; // Gold bricks are never destroyed

    /**
     * @brief Implements Brick::clone.
     */
    virtual std::shared_ptr<Brick> clone();
};

#endif
