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

    void removeOneLife();
    void resetLife();
    void saveScore();

    void setNbLifes(const uint8_t nbLifes);

    uint8_t getNbLifes() const;
};

#endif // LIFE_HPP
