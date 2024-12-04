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

#include "../../model/model.hpp"
#include "../piece/gui_ball.hpp"
#include "../piece/gui_brik.hpp"
#include "../piece/gui_racket.hpp"
#include "../piece/gui_lazer.hpp"

using namespace std;

class Canvas {
private:
  Model model_;
        vector<GuiBall> balls_;
        vector<GuiBrik> briks_;
        vector<GuiRacket> racket_;
        unique_ptr<GuiLazer> lazer_;

    public:
        Canvas(Model model);
        ~Canvas() = default;

        void draw();

        Racket getRacket() const;

        void moveRacket(const float x);
        void moveBall(const float x = 0, const float y = 0);

        void addLazer();
};

#endif // CANVAS_HPP