/**
 * @file life.hpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Define the Life class
 * @date 16/11/2024
 *
 */

#ifndef LIFE_COUNTER_HPP
#define LIFE_COUNTER_HPP

#include <allegro5/bitmap.h>

using namespace std;

class LifeCounter final {
  private:
    unsigned numLifes_;

  public:
    /**
     * @brief Constructs a new LifeCounter.
     */
    LifeCounter();

    LifeCounter(const LifeCounter &) = default;
    LifeCounter(LifeCounter &&) = default;
    LifeCounter &operator=(const LifeCounter &) = default;
    LifeCounter &operator=(LifeCounter &&) = default;

    /**
     * @brief Constructs a new LifeCounter with numLifes lifes remaining.
     *
     * @param numLifes The number of remaining lifes.
     */
    LifeCounter(unsigned numLifes);

    virtual ~LifeCounter();

    /**
     * @brief Resets the number of lifes to the initial number of lifes.
     */
    void reset();

    /**
     * @brief Decrements the number of lifes.
     */
    const LifeCounter &operator--();

    /**
     * @brief Increments the number of lifes.
     */
    const LifeCounter &operator++();

    /**
     * @brief Adds numLife lifes to the counter.
     */
    const LifeCounter &operator+=(unsigned numLife);

    /**
     * @brief Sets the number of lifes to numLifes.
     */
    void setNumLifes(uint8_t numLifes);

    /**
     * @brief Converts the lifeCounter to an unsigned.
     */
    operator unsigned() const;
};

#endif // LIFE_COUNTER_HPP
