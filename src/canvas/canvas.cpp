/**
 * @file canvas.cpp
 * @author Ethan Van Ruyskensvelde (Main developper)
 * @brief Define the class Canvas that will be used to draw all the pieces of the game
 * @date 24/11/2024
 *
 */

#include "canvas.hpp"

// ### Constructor ###
Canvas::Canvas() {
    int startX = 100; // Position initiale de X
    int startY = 300;      // Position initiale de Y (pour j = 0)
    int step = 60;        // Décalage à chaque itération

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 14; j++) {
            briks_.push_back(Rectangle(Point(startX + j * step, startY + i * step), 50, 25, COLOR_RED));
        }
    }
    balls_.push_back(Circle(Point(500, 900), 20, COLOR_BLUE));
}

// ### Public methods ###
void Canvas::draw() {
    for (auto &ball : balls_) {
        ball.draw();
    }

    for (auto &brik : briks_) {
        brik.draw();
    }
}

void Canvas::moveBall(const int x, const int y) {
    Circle ball = balls_[0];
    ball.move(x, y);
}