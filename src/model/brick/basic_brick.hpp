#ifndef BASIC_BRICK_HPP
#define BASIC_BRICK_HPP

#include "brick.hpp"

/**
 * @brief Represents a basic brick.
 */
class BasicBrick final : public Brick {
  public:
    /**
     * @brief Constructs a new BasicBrick.
     * @param boudingBox The brick's BoudingBox.
     * @param color The brick's color.
     * @param durability The brick's durability.
     * @param bonusType The bonus held contained in the brick.
     */
    BasicBrick(BoundingBox boundingBox, Color color, uint8_t durability,
               BonusType bonusType = BonusType::None);

    BasicBrick(const BasicBrick &) = default;
    BasicBrick(BasicBrick &&) = delete;

    BasicBrick &operator=(const BasicBrick &) = default;
    BasicBrick &operator=(BasicBrick &&) = delete;

    virtual ~BasicBrick() = default;
};

#endif
