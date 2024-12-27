#ifndef GAME_BOARD_HPP
#define GAME_BOARD_HPP

#include "../ball/ball.hpp"
#include "../bonus/abstract_timed_bonus.hpp"
#include "../bonus_pill/bonus_pill.hpp"
#include "../bonus_type/bonus_type.hpp"
#include "../border/border.hpp"
#include "../brick/brick.hpp"
#include "../life_counter/life_counter.hpp"
#include "../racket/racket.hpp"
#include "../score_manager/score_manager.hpp"

#include <memory>
#include <optional>
#include <variant>
#include <vector>

using BrickIt = std::vector<std::shared_ptr<Brick>>::const_iterator;
using BorderIt = std::vector<std::shared_ptr<Border>>::const_iterator;

class GameBoard final {
  private:
    ScoreManager scoreManager_;
    LifeCounter lifeCounter_;
    unique_ptr<AbstractTimedBonus> activeBonus_;
    std::vector<unique_ptr<BonusPill>> descendingBonuses_;

    std::shared_ptr<Racket> racket_;
    std::vector<std::shared_ptr<Border>> borders_;
    std::vector<std::shared_ptr<Brick>> bricks_;
    std::vector<std::shared_ptr<Ball>> balls_;

    /**
     * @brief Finds the next collision involving the specified ball.
     *
     * @param ball Reference to the ball involved in the collision.
     * @return An optional variant containing either Brick-iterator or a
     * Border-iterator or a shared_ptr<Racket> corresponding to the next
     * Colliding object. The optional has no value if no collisions were found.
     */
    std::optional<std::variant<BrickIt, BorderIt, shared_ptr<Racket>>>
    findNextCollision(Ball &ball);

    /**
     * @brief Resolves collisions involving the specified ball and
     * calculates the points earned from this collision resolution.
     *
     * @param ball Reference to the ball involved in the collision.
     * @return The number of points earned as a result of resolving the
     * collisions.
     */
    size_t solveBallCollisions(Ball &ball);

    /**
     * @brief Applies the given bonus.
     */
    void applyBonus(BonusType bonusType);

    /**
     * @brief Undoes the effects of the given bonus.
     */
    void undoBonusEffect(BonusType bonusType);

    /**
     * @brief Creates a new ball.
     */
    shared_ptr<Ball> createBall();

    // #### Bonus Split into 3 ####

    /**
     * @brief Adds the 2 newly created balls when the given ball gets split into
     * three.
     */
    void splitBallIntoThree(const Ball &originalBall,
                            std::vector<shared_ptr<Ball>> &newBalls);

    /**
     * @brief Clears and sets up the ball vector for the next game.
     */
    void clearBalls();

    /**
     * @brief Clears the active bonus.
     */
    void clearBonus();

    /**
     * @brief Clears the descending bonuses.
     */
    void clearDescendingBonuses();

    /**
     * @brief Clears the Borders.
     */
    void clearBorders();

    /**
     * @brief Clears the bricks.
     */
    void clearBricks();

  public:
    // #### Constructor ####

    GameBoard() = default;
    GameBoard(const GameBoard &) = delete;
    GameBoard(GameBoard &&) = delete;
    GameBoard &operator=(const GameBoard &) = delete;
    GameBoard &operator=(GameBoard &&) = delete;

    // #### Destructor ####

    virtual ~GameBoard() = default;

    /**
     * @brief Updates the GameBoard state based on elapsed time.
     *
     * @param deltaTime Time elapsed (in seconds) since the last update.
     */
    void update(double deltaTime);

    // #### Getters ####

    /**
     * @brief Returns the current Score.
     *
     * @return The current score.
     */
    unsigned long getScore() const;

    /**
     * @brief Returns a reference to the lifeCounter.
     *
     * @return A reference to the lifeCounter.
     */
    const LifeCounter &getLife() const;

    /**
     * @brief Returns the current number of bricks.
     *
     * @return The current number of bricks.
     */
    unsigned long getNumBricks() const;

    /**
     * @brief Returns the currently active Balls.
     *
     * @return A reference to the vector of ball pointers.
     */
    const std::vector<std::shared_ptr<Ball>> &getBalls() const;

    /**
     * @brief Returns the current Bricks.
     *
     * @return A reference to the vector of brick pointers.
     */
    const std::vector<std::shared_ptr<Brick>> &getBricks() const;

    /**
     * @brief Returns the currently descending bonus pills.
     *
     * @return A reference to the vector of descending bonus pills.
     */
    const std::vector<std::unique_ptr<BonusPill>> &getDescendingBonuses() const;

    /**
     * @brief Returns the racket.
     *
     * @return A reference to the racket pointer.
     */
    const std::shared_ptr<Racket> &getRacket() const;

    /**
     * @brief Returns the map borders.
     *
     * @return A reference to the vector of border pointers.
     */
    const std::vector<std::shared_ptr<Border>> &getBorders() const;

    // #### Setters ####

    /**
     * @brief Sets the racket's horizontal coordinate.
     *
     * @param posX The racket's horizontal coordinate.
     */
    void setRacketAtX(double posX);

    /**
     * @brief Sets the bricks.
     *
     * @param bricks A reference to the vector of brick pointers.
     */
    void setBricks(const std::vector<std::shared_ptr<Brick>> &bricks);

    /**
     * @brief Sets the racket.
     *
     * @param bricks A reference to the racket pointer.
     */
    void setRacket(const std::shared_ptr<Racket> racket);

    /**
     * @brief Sets the borders.
     *
     * @param borders A reference to the vector of border pointers.
     */
    void setBorders(const std::vector<std::shared_ptr<Border>> &borders);

    /**
     * @brief Resets the life counter.
     */
    void resetLifeCounter();

    /**
     * @brief Resets the current score to 0.
     */
    void resetScore();

    /**
     * @brief Saves the best score.
     */
    void saveBestScore();

    /**
     * Returns the best score.
     */
    unsigned long getBestScore() const;

    /**
     * @brief Resets the best score.
     */
    void resetBestScore();

    // #### Clear GameBoard ####

    /**
     * @brief Clears and sets up the board for the next game.
     */
    void clear();
};

#endif
