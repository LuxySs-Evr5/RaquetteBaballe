#include "bonus_pill.hpp"

#include <iostream>

// TODO: remove this
using namespace std;

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
    bool isOverlapping = boundingBox_.isOverlapping(boundingBox_);
    cout << "isOverlapping: " << isOverlapping << endl;
    return isOverlapping;
}

Vec2 BonusPill::getCoordinate() const { return boundingBox_.getCenter(); }
