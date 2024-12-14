/**
 * @file life.cpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Define the Life class
 * @date 16/11/2024
 *
 */

#include "life_counter.hpp"

// ### Constructor ###

LifeCounter::LifeCounter() : numLifes_(INITIAL_NUM_LIFES) {}

LifeCounter::LifeCounter(unsigned numLifes) : numLifes_(numLifes) {}

// ### Destructor ###

LifeCounter::~LifeCounter() = default;

// ### Public Methods ###

const LifeCounter &LifeCounter::operator--() {
    numLifes_--;
    return *this;
}

const LifeCounter &LifeCounter::operator++() {
    numLifes_--;
    return *this;
}

const LifeCounter &LifeCounter::operator+=(unsigned numLife) {
    numLifes_ -= numLife;
    return *this;
}

void LifeCounter::reset() { numLifes_ = INITIAL_NUM_LIFES; }

// ### Setters ###

void LifeCounter::setNumLifes(const uint8_t numLifes) { numLifes_ = numLifes; }

// ### Getters ###

LifeCounter::operator unsigned() const { return numLifes_; }
