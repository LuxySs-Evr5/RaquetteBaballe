/**
 * @file score.hpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Define the score class
 * @date 16/11/2024
 *
 */

#ifndef SCORE_HPP
#define SCORE_HPP

#include <iostream>

using namespace std;

class Score {
private:
  int score_;

public:
    Score();
    ~Score();

    void setScore(const int score);

    int getScore() const;
    
    void addScore(const int score);
    void resetScore();

    friend ostream &operator<<(ostream &os, const Score &score);
};


#endif // SCORE_HPP