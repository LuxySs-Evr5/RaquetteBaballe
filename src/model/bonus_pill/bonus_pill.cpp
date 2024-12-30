#include "bonus_pill.hpp"
#include "../../global_variables.hpp"

BonusPill::BonusPill(const Vec2 &center, BonusType bonusType)
    : RectangleShape{center, BONUS_PILL_WIDTH, BONUS_PILL_HEIGHT},
      bonusType_{bonusType}, descentSpeed_{BONUS_PILL_DESCENT_SPEED} {}

void BonusPill::update(double deltaTime) {
    setCenter(
        {getCenter().x, getCenter().y - BONUS_PILL_DESCENT_SPEED * deltaTime});
}

BonusType BonusPill::getBonusType() const { return bonusType_; }
