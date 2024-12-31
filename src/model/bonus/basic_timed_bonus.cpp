#include "basic_timed_bonus.hpp"
#include "../../global_variables.hpp"

BasicTimedBonus::BasicTimedBonus(BonusType bonusType)
    : AbstractTimedBonus(bonusType) {
    switch (bonusType) {
    case BonusType::WideRacket:
        remaningTime_ = WIDE_RACKET_DURATION;
        break;
    case BonusType::Lazer:
        remaningTime_ = LAZER_DURATION;
        break;
    default:
        break;
    }
}

bool BasicTimedBonus::update(double deltaT) {
    remaningTime_ -= deltaT;
    return (remaningTime_ > 0);
}
