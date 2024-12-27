#include "slowdown_bonus.hpp"

#include <numeric>

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

double SlowDownBonus::getSlowDownFactor() const {
    int sum = std::accumulate(queue_.begin(), queue_.end(), 0);

    return 1 + (SLOW_DOWN_PROPORTIAL_CONST * sum);
}
