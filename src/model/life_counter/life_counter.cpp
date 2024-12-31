/**
 * @file life.cpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Define the Life class
 * @date 16/11/2024
 *
 */

#include "life_counter.hpp"
#include "../../global_variables.hpp"

LifeCounter::LifeCounter() : numLives_(INITIAL_NUM_LIVES) {}

LifeCounter::LifeCounter(unsigned numLives) : numLives_(numLives) {}

LifeCounter::~LifeCounter() = default;

void LifeCounter::reset() { numLives_ = INITIAL_NUM_LIVES; }

const LifeCounter &LifeCounter::operator--() {
    numLives_--;
    return *this;
}

const LifeCounter &LifeCounter::operator++() {
    numLives_++;
    return *this;
}

const LifeCounter &LifeCounter::operator+=(unsigned numLife) {
    numLives_ -= numLife;
    return *this;
}

void LifeCounter::setNumLives(const uint8_t numLives) { numLives_ = numLives; }

LifeCounter::operator unsigned() const { return numLives_; }
