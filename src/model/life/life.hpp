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

class Life {
  private:
    uint8_t nbLifes_; // uint8_t is the lowest integer type that can hold 0 to 3
                      // lifes
    Score score_;

  public:
    Life();
    Life(uint8_t nbLifes);

    ~Life();

    void removeOneLife(); // TODO: use operator--()
    void resetLife();     // TODO: rename to reset

    void setNbLifes(const uint8_t nbLifes);

    operator uint8_t() const; // Operator uint8_t
};

#endif // LIFE_HPP
