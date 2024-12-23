/**
 * @file canvas.cpp
 * @author Ethan Van Ruyskensvelde (Main developper)
 * @brief Define the class Canvas that will be used to draw all the pieces of
 * the game
 * @date 24/11/2024
 *
 */

#include "canvas.hpp"
#include "../piece/brick_ui.hpp"

// ### Constructor ###
Canvas::Canvas(shared_ptr<GameBoard> gameBoard) : gameBoard_(gameBoard) {};

// ### Public methods ###
void Canvas::draw() {
    for (auto &border : borders_) {
        wallRenderer_.render(*border);
    }

    for (auto &brick : bricks_) {
        BrickUi brickUi{brick->getBoundingBox().getCenter().toPoint(),
                        static_cast<float>(brick->getBoundingBox().getWidth()),
                        static_cast<float>(brick->getBoundingBox().getHeight()),
                        colorToAllegroColor(brick->getColor())};
        brickUi.draw(*brick);
    }

    for (auto &bonusPill : bonusPills_) {
        pillRenderer_.render(*bonusPill);
    }

    for (auto &ball : balls_) {
        ballRenderer_.render(*ball);
    }

    racketRenderer_.render(*racket_);
}
