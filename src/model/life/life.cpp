/**
 * @file life.cpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Define the Life class
 * @date 16/11/2024
 *
 */

#include "life.hpp"

// ### Constructor ###

Life::Life() : numLifes_(MAX_NUM_LIFES) {}

Life::Life(uint8_t numLifes) : numLifes_(numLifes) {}

// ### Destructor ###

Life::~Life() = default;

// ### Public Methods ###

void Life::removeOneLife() { numLifes_--; }

void Life::resetLife() { numLifes_ = MAX_NUM_LIFES; }

// ### Setters ###

void Life::setNumLifes(const uint8_t numLifes) { numLifes_ = numLifes; }

// ### Getters ###

Life::operator uint8_t() const { return numLifes_; }
