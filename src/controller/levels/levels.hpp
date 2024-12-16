/**
 * @file levels.hpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Define struct Levels
 * @date 16/12/2024
 *
 */

#ifndef LEVELS_HPP
#define LEVELS_HPP

#include <memory>
#include <vector>
#include "../../model/brick/brick.hpp"
#include "../../model/border/border.hpp"
#include "../../model/racket/racket.hpp"
#include "../../model/ball/ball.hpp"
#include "../../global_variables.hpp"

using namespace std;

constexpr unsigned MAX_LEVEL = 3 - 1; // -1 because we start to count at 0

class Levels {
  private:
        unsigned level = 0;
        vector<shared_ptr<Brick>> levelBricks_ ;
        const Ball levelBall_ = Ball(Vec2{BOARD_WIDTH / 2 + WALL_THICKNESS - 1, 85}, Vec2{0, 1}, 10, 500); // + BOARD_BOUNDINGS_THICKNESS because the board has a left border
        const Racket levelRacket_ = Racket(BoundingBox{Vec2{BOARD_WIDTH / 2 + WALL_THICKNESS - 1, 50}, 100, 25}); // + BOARD_BOUNDINGS_THICKNESS because the board has a left border;
        vector<shared_ptr<Border>> levelBorders_;

        void loadBricks();

      public:
        Levels();
        ~Levels() = default;
        void levelUp();
        void levelDown();
        const vector<shared_ptr<Brick>> getBricks();
        const Ball getBall() const;
        const Racket getRacket() const;
        const vector<shared_ptr<Border>> getBorders() const;
};

#endif // LEVELS_HPP