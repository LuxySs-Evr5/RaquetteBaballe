/**
 * @file life.hpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Define the Life class
 * @date 16/11/2024
 *
 */

#ifndef LIFE_HPP
#define LIFE_HPP

#include <allegro5/bitmap.h>
#include <cstdint>

#include "../score/score.hpp"

using namespace std;

constexpr uint8_t MAX_NUM_LIFES = 3;

class Life {
  private:
    uint8_t numLifes_; // uint8_t is the lowest integer type that can hold 0 to
                       // 3 lifes
    Score score_;

  public:
    Life();
    Life(uint8_t numLifes);

    ~Life();

    void removeOneLife(); // TODO: use operator--()
    void resetLife();     // TODO: rename to reset

    void setNumLifes(const uint8_t numLifes);

    operator uint8_t() const; // Operator uint8_t
};

#endif // LIFE_HPP
