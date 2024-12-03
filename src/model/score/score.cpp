/**
 * @file score.cpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Define the score class
 * @date 16/11/2024
 *
 */

#include "score.hpp"
#include <fstream>

// ### Constructor ###

Score::Score() : score_(0) {}


// ### Destructor ###

Score::~Score() = default;


// ### Public Methods ###

void Score::addScore(const int score) { score_ += score; }

void Score::resetScore() { score_ = 0; }

void Score::save() {
  string filePath = "score.txt";

  ifstream read(filePath, ios::in);

  int fileScore = 0;

  if (read.is_open()) {
    read >> fileScore;
    read.close();
  }

  if (getScore() >= fileScore) { // >= because if the file don't exist and that the best score is 0, it will not create the file
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


// ### Getters ###
int Score::getScore() const { return score_; }

string Score::getScoreString() const { 
  return "Score : " + to_string(score_);
}

