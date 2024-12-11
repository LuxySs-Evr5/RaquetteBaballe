/**
 * @file canvas.cpp
 * @author Ethan Van Ruyskensvelde (Main developper)
 * @brief Define the class Canvas that will be used to draw all the pieces of
 * the game
 * @date 24/11/2024
 *
 */

#include "canvas.hpp"
#include <memory>

// ### Constructor ###
Canvas::Canvas(shared_ptr<GameBoard> gameBoard) : gameBoard_{gameBoard}, racket_(gameBoard->getRacket()), bricks_(gameBoard->getBricks()), balls_(gameBoard->getBalls()), borders_(gameBoard->getBorders()) {
};

// ### Public methods ###
void Canvas::draw() {
    for (auto &ball : balls_) {
        ballRenderer_.render(*ball);
    }

    for (auto &brick : bricks_) {
        brickRenderer_.render(*brick);
    }

    racketRenderer_.render(*racket_);

    for (auto &border : borders_) {
        wallRenderer_.render(*border);
    }
}
