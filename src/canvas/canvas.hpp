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
#include "../global_variables.hpp"
#include "../figures/forme.hpp"
#include "../piece/racket.hpp"
#include "../piece/ball.hpp"
#include "../piece/lazer.hpp"

using namespace std;

class Canvas {
    private:
        vector<Ball> balls_;
        vector<Rectangle> briks_;
        Racket racket_;
        Lazer *lazer_;

    public:
        Canvas();
        ~Canvas() = default;

        void draw();

        Racket getRacket() const;

        void moveRacket(const float x);

        void addLazer(const Lazer &lazer);
};

#endif // CANVAS_HPP