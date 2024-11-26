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

#include "../global_variables.hpp"
#include "../figures/forme.hpp"

using namespace std;

class Canvas {
    private:
        vector<Circle> balls_;
        vector<Rectangle> briks_;
        Rectangle racket_;

    public:
        Canvas(Rectangle racket = Rectangle(Point(500, 940), RACKET_WIDTH, RACKET_HEIGHT, COLOR_WHITE));
        ~Canvas() = default;

        void draw();

        Rectangle getRacket() const { return racket_; }

        void moveRacket(const float x);
};

#endif // CANVAS_HPP