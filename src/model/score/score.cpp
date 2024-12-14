/**
 * @file score.cpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Define the score class
 * @date 16/11/2024
 *
 */

#include "score.hpp"
#include <fstream>
#include <iostream>

// ### Constructor ###

Score::Score() : score_(0) {}

// ### Destructor ###

Score::~Score() = default;

// ### Public Methods ###

void Score::addScore(const int score) { score_ += score; }

void Score::resetScore() { score_ = 0; }

void Score::saveScore() {
    string filePath = "score.txt";

    ifstream read(filePath, ios::in);

    int fileScore = 0;

    if (read.is_open()) {
        read >> fileScore;
        read.close();
    }

    if (*this >= fileScore) { // >= because if the file don't exist and that the
                              // best score is 0, it will not create the file
        ofstream write(filePath, ios::out | ios::trunc);
        if (write.is_open()) {
            write << *this << endl;
            write.close();
        } else {
            std::cerr << "Error: Can't open the file" << std::endl;
        }
    }
}

// ### Getters ###
Score::operator int() const { return score_; }

Score::operator std::string() const { return "Score : " + to_string(score_); }
