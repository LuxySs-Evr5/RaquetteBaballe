/**
 * @file life.hpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Define the Life class
 * @date 16/11/2024
 *
 */

#include <fstream>

#include "life.hpp"
#include "../score/score.hpp"

// ### Constructor ###

Life::Life() : nbLifes_(3) {}

Life::Life(uint8_t nbLifes) : nbLifes_(nbLifes) {}


// ### Destructor ###

Life::~Life() = default;


// ### Public Methods ###

void Life::removeOneLife() {
  nbLifes_--;
  if (nbLifes_ < 1) {
    cout << "Game Over ! Your score is:" << getScore() << endl;
    // TODO: we have to choose what to do when the game is over
  }
}

void Life::saveScore() {
  string filePath = "../../score.txt";

  ifstream read(filePath, ios::in);

  int fileScore = 0;

  if (read.is_open()) {
    read >> fileScore;
    read.close();
  }

  if (getScore() > fileScore) {
    ofstream write(filePath, ios::out | ios::trunc);
    if (write.is_open()) {
      write << getScore() << endl;
      write.close();
    }
    else {
      cerr << "Error: Can't open the file" << endl;
    }
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