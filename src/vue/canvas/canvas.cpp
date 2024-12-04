/**
 * @file canvas.cpp
 * @author Ethan Van Ruyskensvelde (Main developper)
 * @brief Define the class Canvas that will be used to draw all the pieces of the game
 * @date 24/11/2024
 *
 */

#include "canvas.hpp"
#include <vector>

// ### Constructor ###
Canvas::Canvas(Model model) : model_(model) {
  for (auto &ball : model_.getGameBoard().getBalls()) {   
    balls_.push_back(GuiBall(Point(ball->getCoordinate().getX(), ball->getCoordinate().getY()), static_cast<float>(ball->getRadius()), COLOR_BLUE));
  }

  for (auto &brick : model_.getGameBoard().getBricks()) {
    briks_.push_back(GuiBrik(Point(brick->getBoundingBox().getCenter().getX(), brick->getBoundingBox().getCenter().getY()), brick->getBoundingBox().getWidth(), brick->getBoundingBox().getHeight(), COLOR_RED));

  racket_.push_back(GuiRacket(Point(model_.getGameBoard().getRackets().getBoundingBox().getCenter().getX(), model_.getGameBoard().getRackets().getBoundingBox().getCenter().getY()), model_.getGameBoard().getRackets().getBoundingBox().getWidth(), model_.getGameBoard().getRackets().getBoundingBox().getHeight(), COLOR_GREEN));
  }
}


// ### Public methods ###
void Canvas::draw() {
    for (auto &ball : balls_) {
        ball.draw();
    }

    for (auto &brik : briks_) {
        brik.draw();
    }

    for (auto &racket : racket_) {
        racket.draw();
    }
}