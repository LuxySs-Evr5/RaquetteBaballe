/**
 * @file score.hpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Define the score class
 * @date 16/11/2024
 *
 */

#include "score.hpp"
#include <fstream>
#include <string>

// ### Constructor ###

Score::Score() : score_(0) {}


// ### Destructor ###

Score::~Score() = default;


// ### Public Methods ###

void Score::addScore(const int score) { score_ += score; }

void Score::resetScore() { score_ = 0; }

void Score::saveScore() {
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

ostream &operator<<(ostream &os, const Score &score) {
    os << "Score: " << score.score_;
    return os;
}


// ### Setters ###
void Score::setScore(const int score) { score_ = score; }


// ### Getters ###
int Score::getScore() const { return score_; }

string Score::getScoreString() const { 
  return "Score : " + to_string(score_);
}
