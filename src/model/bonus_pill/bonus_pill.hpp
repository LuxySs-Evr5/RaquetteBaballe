#ifndef BONUS_PILL_HPP
#define BONUS_PILL_HPP

#include "../bonus_type/bonus_type.hpp"
#include "../rectangle_shape/rectangle_shape.hpp"

class BonusPill : public RectangleShape {
  private:
    BonusType bonusType_;
    double descentSpeed_;

  public:
    BonusPill(const Vec2 &center, BonusType bonusType);
    BonusPill(const BonusPill &) = default;
    BonusPill(BonusPill &&) = default;

    BonusPill &operator=(const BonusPill &) = default;
    BonusPill &operator=(BonusPill &&) = default;

    /**
     * @brief Returns the BonusPill's BonusType.
     */
    BonusType getBonusType() const;

    /**
     * @brief Updates the BonusPill's position as if it had traveled for a
     * deltaTime duration (seconds).
     * @param deltaTime The duration (seconds).
     */
    void update(double deltaTime);
};

#endif // BONUS_PILL_HPP
