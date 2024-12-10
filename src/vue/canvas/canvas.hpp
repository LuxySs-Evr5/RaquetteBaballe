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

#include "../piece/brik.hpp"
#include "../piece/racket.hpp"
#include "../piece/ball.hpp"

using namespace std;

class Canvas {
    private:
        vector<Ball> balls_;
        vector<Brik> briks_;
        Racket racket_;

    public:
        Canvas();
        ~Canvas() = default;

        void draw();

        Racket getRacket() const;

        void moveRacket(const float x);
        void moveBall(const float x = 0, const float y = 0);
};

#endif // CANVAS_HPP