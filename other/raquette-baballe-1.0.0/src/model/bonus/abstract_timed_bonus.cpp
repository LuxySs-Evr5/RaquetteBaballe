#include "abstract_timed_bonus.hpp"

AbstractTimedBonus::AbstractTimedBonus(BonusType bonusType)
    : bonusType_{bonusType} {}

BonusType AbstractTimedBonus::getBonusType() const { return bonusType_; }
