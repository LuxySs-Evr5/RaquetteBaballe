#ifndef BONUS_PILL_HPP
#define BONUS_PILL_HPP

#include "../bounding_box/bounding_box.hpp"
#include "bonus_type.hpp"

constexpr double BONUS_PILL_WIDTH = 10;
constexpr double BONUS_PILL_HEIGHT = 10;
constexpr double DESCENT_SPEED = 200;

class BonusPill {
  private:
    BonusType bonusType_;
    BoundingBox boundingBox_;
    double descentSpeed_;

  public:
    BonusPill(BonusType bonusType, Vec2 coord);

    BonusType getBonusType();

    void update(double deltaTime);

    bool checkCollision(const BoundingBox &boundingBox);

    Vec2 getCoordinate() const;

    const BoundingBox &getBoundingBox();

    double getWidth() const;

    double getHeight() const;

    BonusType getBonusType() const;
};

#endif // BONUS_PILL_HPP
