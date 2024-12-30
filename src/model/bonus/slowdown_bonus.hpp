#ifndef SLOWDOWN_BONUS_HPP
#define SLOWDOWN_BONUS_HPP

#include "../../global_variables.hpp"
#include "abstract_timed_bonus.hpp"

#include <vector>

class SlowDownBonus final : public AbstractTimedBonus {
  private:
    std::vector<double> queue_;

  public:
    SlowDownBonus();
    SlowDownBonus(const SlowDownBonus &) = default;
    SlowDownBonus(SlowDownBonus &&) = default;

    SlowDownBonus &operator=(const SlowDownBonus &) = default;
    SlowDownBonus &operator=(SlowDownBonus &&) = default;

    virtual ~SlowDownBonus() = default;

    /**
     * @brief Reapplies the SlowDown bonus one more time.
     */
    virtual void reapply() override;

    /**
     * @brief Updates the bonus's remaining duration based on the elapsed time.
     * @param deltaT The time elapsed (in seconds).
     */
    virtual bool update(double deltaT) override;

    /**
     * @brief Returns the slow down factor for the ball.
     */
    virtual double getSlowDownFactor() const;
};

#endif
