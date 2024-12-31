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
    unsigned numLives_;

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
     * @brief Constructs a new LifeCounter with numLives lives remaining.
     *
     * @param numLives The number of remaining lives.
     */
    LifeCounter(unsigned numLives);

    virtual ~LifeCounter();

    /**
     * @brief Resets the number of lives to the initial number of lives.
     */
    void reset();

    /**
     * @brief Decrements the number of lives.
     */
    const LifeCounter &operator--();

    /**
     * @brief Increments the number of lives.
     */
    const LifeCounter &operator++();

    /**
     * @brief Adds numLife lives to the counter.
     */
    const LifeCounter &operator+=(unsigned numLife);

    /**
     * @brief Sets the number of lives to numLives.
     */
    void setNumLives(uint8_t numLives);

    /**
     * @brief Converts the lifeCounter to an unsigned.
     */
    operator unsigned() const;
};

#endif // LIFE_COUNTER_HPP
