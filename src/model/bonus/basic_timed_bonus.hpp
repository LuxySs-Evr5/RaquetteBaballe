#ifndef BASIC_TIMED_BONUS_HPP
#define BASIC_TIMED_BONUS_HPP

#include "abstract_timed_bonus.hpp"

// WideRacket
constexpr double WIDE_RACKET_WIDTH = 200;
constexpr double WIDE_RACKET_DURATION = 10;

class BasicTimedBonus final : public AbstractTimedBonus {
  private:
    double remaningTime_;

  public:
    // #### Constructor ####

    BasicTimedBonus(BonusType bonusType);
    BasicTimedBonus(const BasicTimedBonus &) = default;
    BasicTimedBonus(BasicTimedBonus &&) = default;

    // #### Assignment operator ####

    BasicTimedBonus &operator=(const BasicTimedBonus &) = default;
    BasicTimedBonus &operator=(BasicTimedBonus &&) = default;

    // #### Destructor ####

    virtual ~BasicTimedBonus() = default;

    // #### Update ####

    /**
     * @brief Updates the bonus's remaining duration based on the elapsed time.
     * @param deltaT The time elapsed (in seconds).
     */
    virtual bool update(double deltaT);
};

#endif // BASIC_TIMED_BONUS_HPP
