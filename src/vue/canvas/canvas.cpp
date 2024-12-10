/**
 * @file canvas.cpp
 * @author Ethan Van Ruyskensvelde (Main developper)
 * @brief Define the class Canvas that will be used to draw all the pieces of
 * the game
 * @date 24/11/2024
 *
 */

#include "canvas.hpp"
#include "../../global_variables.hpp"

// ### Constructor ###
Canvas::Canvas() {
    // TODO: implémenter constructeur de canvas ?
};

// ### Public methods ###
void Canvas::draw() {
    for (auto &ball : balls_) {
        ball.draw();
    }

    for (auto &brik : briks_) {
        brik.draw();
    }

    racket_.draw();
}

void Canvas::moveRacket(const float x) {
    // Check if the racket is in the grid
    if ((x - (RACKET_WIDTH / 2) >= LEFT_WALL_X_START + WALL_THICKNESS)
        && (x + (RACKET_WIDTH / 2) <= RIGHT_WALL_X_START)) {
        racket_.moveHorizontally(x);
    } else if ((x <= LEFT_WALL_X_START + WALL_THICKNESS)) {
        racket_.moveHorizontally(LEFT_WALL_X_START + WALL_THICKNESS
                                 + RACKET_WIDTH / 2);
    } else if ((x >= RIGHT_WALL_X_START)) {
        racket_.moveHorizontally(RIGHT_WALL_X_START - RACKET_WIDTH / 2);
    }
}

void Canvas::moveBall(const float x, const float y) {
    // TODO: revoir le déplacement des balles car c'est un vecteur de balles
    balls_[0].moveBall(x, y);
}

// ### Getters ###
RacketUi Canvas::getRacket() const { return racket_; }
