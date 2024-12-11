/**
 * @file canvas.hpp
 * @author Ethan Van Ruyskensvelde (Main developper)
 * @brief Define the class Canvas that will be used to draw all the pieces of
 * the game
 * @date 24/11/2024
 *
 */

#ifndef CANVAS_HPP
#define CANVAS_HPP

#include "../piece/ball_ui.hpp"
#include "../piece/brik_ui.hpp"
#include "../piece/racket_ui.hpp"

#include <vector>

using namespace std;

class Canvas {
  private:
    vector<BallUi> balls_;
    vector<BrikUi> briks_;
    RacketUi racket_;

  public:
    Canvas();
    ~Canvas() = default;

    void draw();

    RacketUi getRacket() const;

    void moveRacket(const float x);
    // void moveBall(const float x = 0, const float y = 0);
};

#endif // CANVAS_HPP
