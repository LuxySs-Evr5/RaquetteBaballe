/**
 * @file life.cpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Define the Life class
 * @date 16/11/2024
 *
 */

#include "life.hpp"

// ### Constructor ###

Life::Life() : nbLifes_(3) {}

Life::Life(uint8_t nbLifes) : nbLifes_(nbLifes) {}

// ### Destructor ###

Life::~Life() = default;

// ### Public Methods ###

void Life::removeOneLife() { nbLifes_--; }

void Life::resetLife() { nbLifes_ = 3; }

// ### Getters ###
uint8_t Life::getNbLifes() const { return nbLifes_; }

// ### Setters ###
void Life::setNbLifes(const uint8_t nbLifes) { nbLifes_ = nbLifes; }
