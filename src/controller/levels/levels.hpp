/**
 * @file levels.hpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Define struct Levels
 * @date 16/12/2024
 *
 */

#ifndef LEVELS_HPP
#define LEVELS_HPP

#include "../../model/ball/ball.hpp"
#include "../../model/border/border.hpp"
#include "../../model/brick/brick.hpp"
#include "../../model/racket/racket.hpp"

#include <cstdlib>
#include <memory>
#include <vector>

using namespace std;

class Levels {
  private:
    unsigned long currentLevel_ = 0;
    vector<vector<shared_ptr<Brick>>> levelBricks_;
    shared_ptr<Ball> levelBall_;
    shared_ptr<Racket> levelRacket_;
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
     * @brief Set the current level to the next one
     *
     */
    void nextLevel();

    /**
     * @brief Set the current level to the previous one
     *
     */
    void previousLevel();

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
    const shared_ptr<Ball> getBall() const;

    /**
     * @brief Get the racket of the current level
     *
     * @return const Racket
     */
    const shared_ptr<Racket> &getRacket() const;

    /**
     * @brief Get the borders of the current level
     *
     * @return const vector<shared_ptr<Border>>
     */
    const vector<shared_ptr<Border>> &getBorders() const;
};

#endif // LEVELS_HPP
