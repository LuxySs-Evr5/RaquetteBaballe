#include "bonus_pill.hpp"

BonusPill::BonusPill(const Vec2 &center, BonusType bonusType)
    : RectangleShape{center, BONUS_PILL_WIDTH, BONUS_PILL_HEIGHT},
      bonusType_{bonusType}, descentSpeed_{DESCENT_SPEED} {}

void BonusPill::update(double deltaTime) {
    setCenter({getCenter().x, getCenter().y - DESCENT_SPEED * deltaTime});
}

BonusType BonusPill::getBonusType() const { return bonusType_; }
