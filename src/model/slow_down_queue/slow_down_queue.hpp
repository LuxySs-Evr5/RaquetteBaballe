#ifndef SLOW_DOWN_QUEUE_HPP
#define SLOW_DOWN_QUEUE_HPP

#include <vector>

class AbstractBonus {};

class BasicBonus {};

class SlowDownQueue {
  private:
    std::vector<size_t> queue_;

  public:
    void push(size_t remainingDuration);

    // TODO: change "multiplicator factor" here
    /**
     * @brief Returns the multiplicator factor (how much slower the ball should
     * go compared to its normal speed).
     *
     * @return By how much to multiply the normal ball speed to get the slowed
     * down speed.
     */
    double update();
};

#endif // SLOW_DOWN_QUEUE_HPP
