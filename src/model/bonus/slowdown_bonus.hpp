#ifndef SLOWDOWN_BONUS_HPP
#define SLOWDOWN_BONUS_HPP

#include "abstract_timed_bonus.hpp"

#include <vector>

// SlowDown
constexpr double SLOW_DOWN_PROPORTIAL_CONST = 0.2;
constexpr double SLOW_DOWN_DURATION = 10;

class SlowDownBonus final : public AbstractTimedBonus {
  private:
    std::vector<double> queue_;

  public:
    // #### Constructor ####

    SlowDownBonus();
    SlowDownBonus(const SlowDownBonus &) = default;
    SlowDownBonus(SlowDownBonus &&) = default;

    // #### Assignment operator ####

    SlowDownBonus &operator=(const SlowDownBonus &) = default;
    SlowDownBonus &operator=(SlowDownBonus &&) = default;

    // #### Destructor ####

    virtual ~SlowDownBonus() = default;

    // #### Reapply SlowDown ####

    /**
     * @brief Reapplies the SlowDown bonus one more time.
     */
    virtual void reapply() override;

    // #### Update ####

    /**
     * @brief Updates the bonus's remaining duration based on the elapsed time.
     * @param deltaT The time elapsed (in seconds).
     */
    virtual bool update(double deltaT) override;

    // #### SlowDown Factor ####

    /**
     * @brief Returns the slow down factor for the ball.
     */
    virtual double getSlowDownFactor() const;
};

#endif
