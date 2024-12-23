#include "bonus_pill.hpp"

BonusPill::BonusPill(BonusType bonusType, struct Vec2 coord)
    : boundingBox_{coord, BONUS_PILL_WIDTH, BONUS_PILL_HEIGHT},
      bonusType_{bonusType}, descentSpeed_{DESCENT_SPEED} {}

BonusType BonusPill::getBonusType() { return bonusType_; }

void BonusPill::update(double deltaTime) {
    Vec2 newPos{getCoordinate().x,
                getCoordinate().y - DESCENT_SPEED * deltaTime};

    boundingBox_.setCenter(newPos);
}

bool BonusPill::checkCollision(const BoundingBox &boundingBox) {
    return boundingBox_.isOverlapping(boundingBox);
}

Vec2 BonusPill::getCoordinate() const { return boundingBox_.getCenter(); }

const BoundingBox &BonusPill::getBoundingBox() { return boundingBox_; }
