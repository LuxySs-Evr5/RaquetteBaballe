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

class LifeCounter {
  private:
    unsigned numLifes_;

  public:
    // ### Constructors ###

    LifeCounter();
    LifeCounter(unsigned numLifes);

    // ### Destructor ###

    ~LifeCounter();

    // #### Reset Value ####

    void reset();

    // ### Arithmetic Operators ###

    const LifeCounter &operator--();
    const LifeCounter &operator++();
    const LifeCounter &operator+=(unsigned numLife);

    // ### Setters ###

    void setNumLifes(uint8_t numLifes);

    // ### Conversion Operators ###

    operator unsigned() const;
};

#endif // LIFE_COUNTER_HPP
