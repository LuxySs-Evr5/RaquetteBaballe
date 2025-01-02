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

using namespace std;

class Canvas {
  private:
    shared_ptr<GameBoard> gameBoard_;
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
    virtual ~Canvas() = default;

    /**
     * @brief Draw all the elements of the game
     *
     */
    void draw();
};

#endif // CANVAS_HPP
