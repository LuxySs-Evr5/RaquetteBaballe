/**
 * @file levels.hpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Define struct Levels
 * @date 16/12/2024
 *
 */

#ifndef LEVELS_HPP
#define LEVELS_HPP

#include "../../global_variables.hpp"
#include "../../model/ball/ball.hpp"
#include "../../model/border/border.hpp"
#include "../../model/brick/brick.hpp"
#include "../../model/racket/racket.hpp"

#include <vector>

using namespace std;

constexpr unsigned MAX_LEVEL = 6 - 1; // -1 because we start to count at 0

class Levels {
  private:
    unsigned currentLevel;
    vector<shared_ptr<Brick>> levelBricks_;
    const Ball levelBall_ =
        Ball(Vec2{BOARD_WIDTH / 2 + WALL_THICKNESS - 1, 85}, Vec2{0, 1},
             BALL_RADIUS, BALL_SPEED); // + BOARD_BOUNDINGS_THICKNESS because
                                       // the board has a left border
    const Racket levelRacket_ = Racket(BoundingBox{
        Vec2{BOARD_WIDTH / 2 + WALL_THICKNESS - 1, 50}, RACKET_WIDTH,
        RACKET_HEIGHT}); // + BOARD_BOUNDINGS_THICKNESS because the board has a
                         // left border;
    vector<shared_ptr<Border>> levelBorders_;

    /**
     * @brief Load the bricks of the current level by reading a file in
     * resources/levels/
     *
     */
    void loadBricks();

  public:
    /**
     * @brief Construct and destruct the Levels object
     *
     */
    Levels();
    ~Levels() = default;

    /**
     * @brief Set one level up
     *
     */
    void levelUp();

    /**
     * @brief Set one level down
     *
     */
    void levelDown();

    /**
     * @brief Get the brick of the current level
     *
     * @return const vector<shared_ptr<Brick>>
     */
    const vector<shared_ptr<Brick>> &getBricks();

    /**
     * @brief Get the ball of the current level
     *
     * @return const Ball
     */
    const Ball &getBall() const;

    /**
     * @brief Get the racket of the current level
     *
     * @return const Racket
     */
    const Racket &getRacket() const;

    /**
     * @brief Get the borders of the current level
     *
     * @return const vector<shared_ptr<Border>>
     */
    const vector<shared_ptr<Border>> &getBorders() const;
};

#endif // LEVELS_HPP
