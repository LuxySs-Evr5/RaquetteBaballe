/**
 * @file score.hpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Define the score class
 * @date 16/11/2024
 *
 */

#ifndef SCORE_MANAGER_HPP
#define SCORE_MANAGER_HPP

constexpr int DEFAULT_SCORE = 0;

class ScoreManager {
  private:
    int currentScore_;
    int recordScore_;

  public:
    // #### Constructors ####

    ScoreManager();

    // #### Destructor ####

    ~ScoreManager();

    // #### Score Actions ####

    void increaseScore(int value);
    void resetScore();
    void saveScore();
    int getCurrentScore() const;
    int getRecordScore() const;
    void setScore0();
};

#endif // SCORE_HPP
