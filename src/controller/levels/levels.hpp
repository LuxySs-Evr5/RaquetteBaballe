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

using namespace std;

class Levels {
    private :
        vector<shared_ptr<Brick>> levelBricks_ ;  // Contient plusieurs vecteurs de Brick
        vector<shared_ptr<Ball>> levelBalls_;    // Contient plusieurs vecteurs de Ball
        vector<shared_ptr<Racket>> levelRackets_; // Contient plusieurs vecteurs de Racket
        vector<shared_ptr<Border>> levelBorders_; // Contient plusieurs vecteurs de Border

        void loadBricks();

      public:
        Levels();
        ~Levels() = default;

        vector<shared_ptr<Ball>> getBalls() const;
        vector<shared_ptr<Racket>> getRackets() const;
        vector<shared_ptr<Border>> getBorders() const;
        vector<shared_ptr<Brick>> getBricks();
};

#endif // LEVELS_HPP