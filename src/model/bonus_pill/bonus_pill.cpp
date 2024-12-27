#include "bonus_pill.hpp"

BonusPill::BonusPill(BonusType bonusType, Vec2 pos)
    : boundingBox_{pos, BONUS_PILL_WIDTH, BONUS_PILL_HEIGHT},
      bonusType_{bonusType}, descentSpeed_{DESCENT_SPEED} {}

void BonusPill::update(double deltaTime) {
    Vec2 newPos{getPos().x, getPos().y - DESCENT_SPEED * deltaTime};

    boundingBox_.setCenter(newPos);
}

bool BonusPill::checkCollision(const BoundingBox &boundingBox) {
    return boundingBox_.isOverlapping(boundingBox);
}

const Vec2 &BonusPill::getPos() const { return boundingBox_.getCenter(); }

const BoundingBox &BonusPill::getBoundingBox() const { return boundingBox_; }

double BonusPill::getWidth() const { return boundingBox_.getWidth(); }

double BonusPill::getHeight() const { return boundingBox_.getHeight(); }

BonusType BonusPill::getBonusType() const { return bonusType_; }
