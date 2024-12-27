/**
 * @file level_manager.hpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Define class LevelManager
 * @date 16/12/2024
 *
 */

#ifndef LEVEL_MANAGER_HPP
#define LEVEL_MANAGER_HPP

#include "../../model/border/border.hpp"
#include "../../model/brick/brick.hpp"
#include "../../model/racket/racket.hpp"

#include <cstdlib>
#include <memory>
#include <vector>

using namespace std;

class LevelManager {
  private:
    unsigned long currentLevel_ = 0;
    vector<vector<shared_ptr<Brick>>> bricksPerLevel_;
    shared_ptr<Racket> racket_;
    vector<shared_ptr<Border>> borders_;

    /**
     * @brief Load the bricks of the current level by reading a file in
     * resources/levels/
     *
     */
    void loadBricks();

  public:
    /**
     * @brief Construct and destruct the LevelManager object
     *
     */
    LevelManager();
    ~LevelManager() = default;

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

#endif // LEVEL_MANAGER_HPP
