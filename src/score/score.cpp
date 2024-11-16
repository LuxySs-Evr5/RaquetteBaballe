/**
 * @file score.hpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Define the score class
 * @date 16/11/2024
 *
 */

#include "score.hpp"

// ### Constructor ###

Score::Score() : score_(0) {}


// ### Destructor ###

Score::~Score() = default;


// ### Public Methods ###

void Score::addScore(const int score) { score_ += score; }

void Score::resetScore() { score_ = 0; }

ostream &operator<<(ostream &os, const Score &score) {
    os << "Score: " << score.score_;
    return os;
}


// ### Setters ###
void Score::setScore(const int score) { score_ = score; }


// ### Getters ###

int Score::getScore() const { return score_; }

