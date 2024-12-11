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


#include "../../model/game_board/game_board.hpp"
#include "../racket_renderer/racket_renderer.hpp"
#include "../ball_renderer/ball_renderer.hpp"
#include "../brick_renderer/brick_renderer.hpp"


#include <memory>
#include <vector>

using namespace std;

// TODO: mettre const

class Canvas {
  private:
    shared_ptr<GameBoard> gameBoard_;
    shared_ptr<Racket> &racket_;
    vector<shared_ptr<Brick>> &bricks_;
    vector<shared_ptr<Ball>> &balls_;
    BallRenderer ballRenderer_;
    BrickRenderer brickRenderer_;
    RacketRenderer racketRenderer_;
    

  public:
    Canvas(shared_ptr<GameBoard> gameBoard);
    ~Canvas() = default;

    void draw();

};

#endif // CANVAS_HPP
