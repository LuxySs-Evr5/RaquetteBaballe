#include "slow_down_queue.hpp"

void SlowDownQueue::push(size_t remainingDuration) {
    queue_.emplace_back(remainingDuration);
}

double SlowDownQueue::update() {
    for (size_t &remainingDuration : queue_) {
        remainingDuration--;
    }

    while (!queue_.empty() && queue_.front() == 0) {
        queue_.erase(queue_.begin());
    }

    return queue_.size();
}
