#include "basic_timed_bonus.hpp"
#include "../../global_variables.hpp"

BasicTimedBonus::BasicTimedBonus(BonusType bonusType)
    : AbstractTimedBonus(bonusType) {
    switch (bonusType) {
    case BonusType::WideRacket:
        remainingTime_ = WIDE_RACKET_DURATION;
        break;
    case BonusType::Lazer:
        remainingTime_ = LAZER_DURATION;
        break;
    case BonusType::StickyRacket:
        remainingTime_ = STICKY_RACKET_DURATION;
        break;
    default:
        break;
    }
}

bool BasicTimedBonus::update(double deltaT) {
    remainingTime_ -= deltaT;
    return (remainingTime_ > 0);
}
