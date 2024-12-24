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

#include <allegro5/allegro_font.h>
#include <memory>
#include <vector>

using namespace std;

class Canvas {
  private:
    shared_ptr<GameBoard> gameBoard_;
    const shared_ptr<Racket> &racket_ = gameBoard_->getRacket();
    const vector<shared_ptr<Brick>> &bricks_ = gameBoard_->getBricks();
    const vector<unique_ptr<BonusPill>> &bonusPills_ =
        gameBoard_->getDescendingBonusses();
    const vector<shared_ptr<Ball>> &balls_ = gameBoard_->getBalls();
    const vector<shared_ptr<Border>> &borders_ = gameBoard_->getBorders();

    ALLEGRO_FONT *fontBrick_;

  public:
    /**
     * @brief Construct a new Canvas object
     *
     * @param gameBoard
     * @param fontBrick the font for the bricks bonus
     */
    Canvas(shared_ptr<GameBoard> gameBoard, ALLEGRO_FONT *fontBrick);

    /**
     * @brief Destroy the Canvas object
     *
     */
    ~Canvas() = default;

    /**
     * @brief Draw all the elements of the game
     *
     */
    void draw();
};

#endif // CANVAS_HPP
