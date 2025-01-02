#ifndef ABSTRACT_TIMED_BONUS_HPP
#define ABSTRACT_TIMED_BONUS_HPP

#include "../bonus/bonus_type.hpp"

class AbstractTimedBonus {
  private:
    BonusType bonusType_;

  protected:
    AbstractTimedBonus(BonusType bonusType);
    AbstractTimedBonus(const AbstractTimedBonus &) = default;
    AbstractTimedBonus(AbstractTimedBonus &&) = default;
    AbstractTimedBonus &operator=(const AbstractTimedBonus &) = default;
    AbstractTimedBonus &operator=(AbstractTimedBonus &&) = default;

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

#endif
