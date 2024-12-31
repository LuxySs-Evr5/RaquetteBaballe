#ifndef BASIC_TIMED_BONUS_HPP
#define BASIC_TIMED_BONUS_HPP

#include "abstract_timed_bonus.hpp"

class BasicTimedBonus final : public AbstractTimedBonus {
  private:
    double remaningTime_;

  public:
    BasicTimedBonus(BonusType bonusType);
    BasicTimedBonus(const BasicTimedBonus &) = default;
    BasicTimedBonus(BasicTimedBonus &&) = default;

    BasicTimedBonus &operator=(const BasicTimedBonus &) = default;
    BasicTimedBonus &operator=(BasicTimedBonus &&) = default;

    virtual ~BasicTimedBonus() = default;

    /**
     * @brief Updates the bonus's remaining duration based on the elapsed time.
     * @param deltaT The time elapsed (in seconds).
     */
    virtual bool update(double deltaT);
};

#endif // BASIC_TIMED_BONUS_HPP
