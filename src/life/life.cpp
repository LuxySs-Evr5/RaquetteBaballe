/**
 * @file life.hpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Define the Life class
 * @date 16/11/2024
 *
 */

#include "../global_variables.hpp"
#include <iostream>
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
    isGaming_ = false;
    cout << "Game Over ! Your score is:" << score_.getScore() << endl; // from ../score/score.hpp
    // TODO: we have to check the score in file score.txt and set the highest
    // score between the score in the file and the current score
    // TODO: we have to choose what to do when the game is over
  }
}

bool Life::currentlyGaming() const { return isGaming_; }

ostream &operator<<(ostream &os, const Life &life) {
  for (int i = 0; i < life.nbLifes_; i++) {
    os << "Number of lifes: " << life.nbLifes_ << endl;
  }
  return os;
}

// ### Getters ###

uint8_t Life::getNbLifes() const { return nbLifes_; }


// ### Setters ###

void Life::setNbLifes(const uint8_t nbLifes) { nbLifes_ = nbLifes; }