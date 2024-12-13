/**
 * @file score.hpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Define the score class
 * @date 16/11/2024
 *
 */

#ifndef SCORE_HPP
#define SCORE_HPP

#include <string>

using namespace std;

class Score {
  private:
    // TODO: verify if the score is very high, so int or long int or lon long
    // int ?
    int score_;

  public:
    Score();
    ~Score();

    void addScore(const int score);
    void resetScore();
    void saveScore();

    int getScore() const;
    string getScoreString() const;
};

#endif // SCORE_HPP
