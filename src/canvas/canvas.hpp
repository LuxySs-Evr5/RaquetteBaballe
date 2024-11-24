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

#include "../figures/forme.hpp"

using namespace std;

class Canvas {
    private:
        vector<Circle> balls_;
        vector<Rectangle> briks_;
        vector<Rectangle> racket_;

    public:
        Canvas();
        ~Canvas() = default;

        void draw();

        void moveBall(const int x, const int y);
};

#endif // CANVAS_HPP