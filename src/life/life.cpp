/**
 * @file life.hpp
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

void Life::removeOneLife() {
  nbLifes_--;
  if (nbLifes_ < 1) {
    nbLifes_ = 0;
  }
}

ostream &operator<<(ostream &os, const Life &life) {
  os << "Numbers of Lifes: " << life.nbLifes_;
  return os;
}

// ### Getters ###

uint8_t Life::getNbLifes() const { return nbLifes_; }


// ### Setters ###

void Life::setNbLifes(const uint8_t nbLifes) { nbLifes_ = nbLifes; }