#ifndef BASIC_BRICK_HPP
#define BASIC_BRICK_HPP

#include "abstract_brick.hpp"

/**
 * @brief Represents a basic brick.
 */
class BasicBrick final : public AbstractBrick {
  public:
    /**
     * @brief Constructs a new BasicBrick.
     * @param center The brick's center.
     * @param width The brick's width.
     * @param height The brick's height.
     * @param color The brick's color.
     * @param durability The brick's durability.
     * @param bonusType The bonus held contained in the brick.
     */
    BasicBrick(const Vec2 &center, double width, double height, Color color,
               uint8_t durability, BonusType bonusType = BonusType::None);

    virtual ~BasicBrick() = default;

    /**
     * @brief Implements AbstractBrick::clone.
     */
    virtual std::shared_ptr<AbstractBrick> clone() override;
};

#endif
