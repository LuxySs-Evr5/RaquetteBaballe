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
    unsigned long currentScore_;
    unsigned long bestScore_;

  public:
    // #### Constructors ####

    /**
     * @brief Constructs a new ScoreManager.
     */
    ScoreManager();
    ScoreManager(const ScoreManager &) = default;
    ScoreManager(ScoreManager &&) = delete;

    // #### Assignment ####

    ScoreManager &operator=(const ScoreManager &) = default;
    ScoreManager &operator=(ScoreManager &&) = delete;

    /**
     * @brief Constructs a new ScoreManager.
     */
    ScoreManager(unsigned long currentScore, unsigned long bestScore)
        : currentScore_(currentScore), bestScore_(bestScore) {}

    // #### Destructor ####

    virtual ~ScoreManager() = default;

    // #### Score Actions ####

    /**
     * @brief Increases the score by the given value.
     */
    void increaseScore(unsigned long value);

    /**
     * @brief Resets the score to the default score.
     */
    void resetScore();

    /**
     * @brief Saves the score.
     */
    void saveScore();

    /**
     * @brief Returns the current score.
     */
    unsigned long getCurrentScore() const;

    /**
     * @brief Returns the best score.
     */
    unsigned long getBestScore() const;

    // TODO: this is weird
    /**
     * @brief Writes 0 in the bestScore file.
     */
    void setScore0();
};

#endif // SCORE_HPP
