/**
 * @file canvas.hpp
 * @author Ethan Van Ruyskensvelde (Main developper)
 * @brief Define the class Canvas that will be used to draw all the pieces of the game
 * @date 24/11/2024
 *
 */

#ifndef CANVAS_HPP
#define CANVAS_HPP

#include <vector>

#include <memory>
#include "../piece/brik.hpp"
#include "../piece/racket.hpp"
#include "../piece/ball.hpp"
#include "../piece/lazer.hpp"

using namespace std;

class Canvas {
    private:
        vector<Ball> balls_;
        vector<Brik> briks_;
        Racket racket_;
        unique_ptr<Lazer> lazer_;

    public:
        Canvas();
        ~Canvas() = default;

        void draw();

        Racket getRacket() const;

        void moveRacket(const float x);
        void moveBall(const float x = 0, const float y = 0);

        void addLazer();
};

#endif // CANVAS_HPP