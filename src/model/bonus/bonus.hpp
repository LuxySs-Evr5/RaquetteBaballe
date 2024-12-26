#ifndef BONUS_HPP
#define BONUS_HPP

#include "bonus_type.hpp"

#include <vector>

// #### Bonuses constants ####
// SlowDown
constexpr double SLOW_DOWN_PROPORTIAL_CONST = 0.2;
constexpr double SLOW_DOWN_DURATION = 10;
// WideRacket
constexpr double WIDE_RACKET_WIDTH = 200;
constexpr double WIDE_RACKET_DURATION = 10;

class AbstractTimedBonus {
  private:
    BonusType bonusType_;

  protected:
    AbstractTimedBonus(BonusType bonusType);
    AbstractTimedBonus(const AbstractTimedBonus &) = delete;
    AbstractTimedBonus(AbstractTimedBonus &&) = delete;
    AbstractTimedBonus &operator=(const AbstractTimedBonus &) = delete;
    AbstractTimedBonus &operator=(AbstractTimedBonus &&) = delete;

  public:
    virtual ~AbstractTimedBonus() = default;

    /**
     * @brief Returns the BonusType.
     */
    BonusType getBonusType() const;

    /**
     * @brief Updates the bonus's remaining duration based on the elapsed time.
     * @param deltaT The time elapsed (in seconds).
     */
    virtual bool update(double deltaT) = 0;

    /**
     * @brief Reapplies the bonus one more time.
     */
    virtual void reapply() {};
};

class BasicTimedBonus final : public AbstractTimedBonus {
  private:
    double remaningTime_;

  public:
    // #### Constructor ####

    BasicTimedBonus(BonusType bonusType);
    BasicTimedBonus(const BasicTimedBonus &) = delete;
    BasicTimedBonus(BasicTimedBonus &&) = delete;

    // #### Assignment operator ####

    BasicTimedBonus &operator=(const BasicTimedBonus &) = delete;
    BasicTimedBonus &operator=(BasicTimedBonus &&) = delete;

    // #### Destructor ####

    virtual ~BasicTimedBonus() = default;

    // #### Update ####

    /**
     * @brief Updates the bonus's remaining duration based on the elapsed time.
     * @param deltaT The time elapsed (in seconds).
     */
    virtual bool update(double deltaT);
};

class SlowDownBonus final : public AbstractTimedBonus {
  private:
    std::vector<double> queue_;

  public:
    // #### Constructor ####

    SlowDownBonus();
    SlowDownBonus(const SlowDownBonus &) = delete;
    SlowDownBonus(SlowDownBonus &&) = delete;

    // #### Assignment operator ####

    SlowDownBonus &operator=(const SlowDownBonus &) = delete;
    SlowDownBonus &operator=(SlowDownBonus &&) = delete;

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

#endif // BONUS_HPP
