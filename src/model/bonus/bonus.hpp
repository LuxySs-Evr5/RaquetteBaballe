#ifndef BONUS_HPP
#define BONUS_HPP

#include "bonus_type.hpp"

#include <vector>

// #### Bonuses constants ####
// SlowDown
constexpr double SLOW_DOWN_SPEED = 100;
constexpr double SLOW_DOWN_DURATION = 10;
// WideRacket
constexpr double WIDE_RACKET_WIDTH = 200;
constexpr double WIDE_RACKET_DURATION = 10;

class AbstractTimedBonus {
  private:
    BonusType bonusType_;

  public:
    AbstractTimedBonus(BonusType bonusType);

    virtual ~AbstractTimedBonus() = default;

    BonusType getBonusType() const;

    virtual bool update(double deltaT) = 0;

    virtual void reapply() {};
};

class BasicTimedBonus final : public AbstractTimedBonus {
  private:
    double remaningTime_;

  public:
    BasicTimedBonus(BonusType bonusType);

    bool update(double deltaT);
};

class SlowDownBonus final : public AbstractTimedBonus {
  private:
    std::vector<double> queue_;

  public:
    SlowDownBonus();

    void reapply() override;

    bool update(double deltaT) override;

    /**
     * @brief Returns the slow down factor for the ball.
     */
    double getSlowDownFactor() const;
};

#endif // BONUS_HPP
