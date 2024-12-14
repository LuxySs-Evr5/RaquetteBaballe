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

#include <sys/types.h>

#include "../score/score.hpp"

using namespace std;

constexpr unsigned INITIAL_NUM_LIFES = 3;

class LifeCounter {
  private:
    unsigned numLifes_;
    Score score_;

  public:
    LifeCounter();
    LifeCounter(unsigned numLifes);

    ~LifeCounter();

    const LifeCounter &operator--();
    const LifeCounter &operator++();
    const LifeCounter &operator+=(unsigned numLife);

    void reset();

    void setNumLifes(const uint8_t numLifes);

    operator unsigned() const;
};

#endif // LIFE_COUNTER_HPP
