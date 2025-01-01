#ifndef GAME_BOARD_HPP
#define GAME_BOARD_HPP

#include "../ball/ball.hpp"
#include "../bonus/abstract_timed_bonus.hpp"
#include "../bonus_pill/bonus_pill.hpp"
#include "../bonus_type/bonus_type.hpp"
#include "../border/border.hpp"
#include "../brick/abstract_brick.hpp"
#include "../lazer/lazer.hpp"
#include "../life_counter/life_counter.hpp"
#include "../racket/racket.hpp"
#include "../score_manager/score_manager.hpp"

#include <memory>
#include <optional>
#include <variant>
#include <vector>

using BrickIt = std::vector<std::shared_ptr<AbstractBrick>>::const_iterator;
using BorderIt = std::vector<std::shared_ptr<Border>>::const_iterator;

constexpr size_t MAX_CONSECUTIVE_COLLISION = 3;

class GameBoard final {
  private:
    ScoreManager scoreManager_;
    LifeCounter lifeCounter_;
    unique_ptr<AbstractTimedBonus> activeBonus_;
    std::vector<shared_ptr<BonusPill>> descendingBonuses_;
    std::vector<std::shared_ptr<Lazer>> lazers_;

    std::shared_ptr<Racket> racket_;
    std::vector<std::shared_ptr<Border>> borders_;
    std::vector<std::shared_ptr<AbstractBrick>> bricks_;
    std::vector<std::shared_ptr<Ball>> balls_;

    template <typename T>
    static void
    removeSharedPointers(std::vector<std::shared_ptr<T>> &mainVector,
                         const std::vector<std::shared_ptr<T>> &toRemove);

    /**
     * @brief Finds the next collision involving the specified ball.
     *
     * @param ball The ball involved in the collision.
     * @return An optional variant containing either Brick-iterator or a
     * Border-iterator or a shared_ptr<Racket> corresponding to the next
     * Colliding object. The optional has no value if no collisions were found.
     */
    std::optional<std::variant<BrickIt, BorderIt, shared_ptr<Racket>>>
    findNextCollision(Ball &ball);

    /**
     * @brief Resolves collisions for the specified ball.
     *
     * @param ball Reference to the ball involved in the collision.
     */
    void solveBallCollisions(Ball &ball);

    /**
     * @brief Creates a new ball and returns the pointer to it.
     */
    shared_ptr<Ball> createBall();

    /**
     * @brief Applies the given bonus.
     *
     * @param bonusType The bonusType.
     */
    void applyBonus(BonusType bonusType);

    /**
     * @brief Undoes the effects of the given bonus.
     *
     * @param bonusType The bonusType.
     */
    void undoBonusEffect(BonusType bonusType);

    /**
     * @brief Adds a new descending bonus.
     *
     * @param center The center coordinate.
     * @param bonusType The BonusType.
     */
    void addDescendingBonus(const Vec2 &center, BonusType bonusType);

    /**
     * @brief Returns the number of balls currently active.
     */
    size_t numBalls();

    /**
     * @brief Adds the 2 newly created balls when the given ball gets split into
     * three.
     * @param originalBall The ball that gets split.
     * @param newBalls Contains the 2 newly created balls.
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
    void clearActiveBonus();

    /**
     * @brief Clears the lazers.
     */
    void clearLazers();

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

    /**
     * @brief Handles the collision between the given ball and brick and updates
     * to the brick's color.
     *
     * @param ball The ball.
     * @param brickIt A brick iterator on the brick on which the collision is
     * happening.
     */
    void handleBallBrickCollision(Ball &ball, BrickIt brickIt);

    /**
     * @brief Handles and updates the descending BonusPills.
     *
     * @param deltaTime The time elapsed since the last update.
     */
    void handleDescendingBonuses(double deltaTime);

    /**
     * @brief Handles and updates the active bonus.
     *
     * @param deltaTime The time elapsed since the last update.
     */
    void handleActiveBonus(double deltaTime);

    /**
     * @brief Handles and updates the moving lazers and the score accordingly.
     *
     * @param deltaTime The time elapsed since the last update.
     */
    void handleLazers(double deltaTime);

    /**
     * @brief Handles and updates the balls.
     *
     * @param deltaTime The time elapsed since the last update.
     */
    void handleBalls(double deltaTime);

    /**
     * @brief Updates the life counter. (Removes remaining life if necessary).
     */
    void updateLifeCounter();

  public:
    GameBoard() = default;
    GameBoard(const GameBoard &) = delete;
    GameBoard(GameBoard &&) = delete;
    GameBoard &operator=(const GameBoard &) = delete;
    GameBoard &operator=(GameBoard &&) = delete;

    virtual ~GameBoard() = default;

    /**
     * @brief Updates the GameBoard state based on elapsed time.
     *
     * @param deltaTime Time elapsed (in seconds) since the last update.
     */
    void update(double deltaTime);

    /**
     * @brief Shoots a lazer.
     */
    void shootLazer();

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
     * @brief Returns the current AbstractBricks.
     *
     * @return A reference to the vector of brick pointers.
     */
    const std::vector<std::shared_ptr<AbstractBrick>> &getBricks() const;

    /**
     * @brief Returns the currently descending bonus pills.
     *
     * @return A reference to the vector of descending bonus pills.
     */
    const std::vector<std::shared_ptr<BonusPill>> &getDescendingBonuses() const;

    /**
     * @brief Returns the racket.
     *
     * @return A reference to the racket.
     */
    const Racket &getRacket() const;

    /**
     * @brief Returns the map borders.
     *
     * @return A reference to the vector of border pointers.
     */
    const std::vector<std::shared_ptr<Border>> &getBorders() const;

    /**
     * @brief Returns the lazers vector.
     *
     * @return A reference to the vector of lazer pointers.
     */
    const std::vector<std::shared_ptr<Lazer>> &getLazers() const;

    /**
     * @brief Sets the racket's horizontal coordinate.
     *
     * @param centerX The racket's horizontal coordinate.
     */
    void setRacketAtX(double centerX);

    /**
     * @brief Sets the bricks.
     *
     * @param bricks A reference to the vector of brick pointers.
     */
    void setBricks(const std::vector<std::shared_ptr<AbstractBrick>> &bricks);

    /**
     * @brief Sets the racket.
     *
     * @param racket A racket pointer.
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

    /**
     * @brief Clears and sets up the board for the next game.
     */
    void clear();
};

#endif
