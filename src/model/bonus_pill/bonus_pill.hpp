#ifndef BONUS_PILL_HPP
#define BONUS_PILL_HPP

#include "../bonus_type/bonus_type.hpp"
#include "../bounding_box/bounding_box.hpp"

constexpr double BONUS_PILL_WIDTH = 10;
constexpr double BONUS_PILL_HEIGHT = 10;
constexpr double DESCENT_SPEED = 200;

class BonusPill {
  private:
    BoundingBox boundingBox_;
    BonusType bonusType_;
    double descentSpeed_;

  public:
    BonusPill(BonusType bonusType, Vec2 pos);
    BonusPill(const BonusPill &) = default;
    BonusPill(BonusPill &&) = default;

    BonusPill &operator=(const BonusPill &) = default;
    BonusPill &operator=(BonusPill &&) = default;

    /**
     * @brief Returns the BonusPill's position.
     */
    const Vec2 &getPos() const;

    /**
     * @brief Returns the BonusPill's BoundingBox.
     */
    const BoundingBox &getBoundingBox() const;

    /**
     * @brief Returns the BonusPill's width.
     */
    double getWidth() const;

    /**
     * @brief Returns the BonusPill's height.
     */
    double getHeight() const;

    /**
     * @brief Returns the BonusPill's BonusType.
     */
    BonusType getBonusType() const;

    /**
     * @brief Checks whether the BonusPill has collided with the given
     * BoundingBox.
     */
    bool checkCollision(const BoundingBox &boundingBox);

    /**
     * @brief Updates the BonusPill's position as if it had travelled for a
     * deltaTime duration (seconds).
     * @param deltaTime The duration (seconds).
     */
    void update(double deltaTime);
};

#endif // BONUS_PILL_HPP
