#include "bonus.hpp"
#include "bonus_type.hpp"

/* ----------------------------
 *          AbstractBonus
 * ---------------------------- */

AbstractTimedBonus::AbstractTimedBonus(BonusType bonusType)
    : bonusType_{bonusType} {}

BonusType AbstractTimedBonus::getBonusType() const { return bonusType_; }

/* ----------------------------
 *          BasicBonus
 * ---------------------------- */

BasicTimedBonus::BasicTimedBonus(BonusType bonusType)
    : AbstractTimedBonus(bonusType) {
    switch (bonusType) {
    case BonusType::WideRacket:
        remaningTime_ = WIDE_RACKET_DURATION;
        break;
    default:
        break;
    }
}

bool BasicTimedBonus::update(double deltaT) {
    remaningTime_ -= deltaT;
    return (remaningTime_ > 0);
}

/* ----------------------------
 *          SlowDown
 * ---------------------------- */

SlowDownBonus::SlowDownBonus() : AbstractTimedBonus(BonusType::SlowDown) {
    // enqueue one SlowDown at construction
    reapply();
}

void SlowDownBonus::reapply() { queue_.emplace_back(SLOW_DOWN_DURATION); }

bool SlowDownBonus::update(double deltaT) {
    for (double &remainingDuration : queue_) {
        remainingDuration -= deltaT;
    }

    while (!queue_.empty() && queue_.front() <= 0) {
        queue_.erase(queue_.begin());
    }

    return (queue_.size() > 0);
}

double SlowDownBonus::getSlowDownFactor() const { return queue_.size() + 1; }
