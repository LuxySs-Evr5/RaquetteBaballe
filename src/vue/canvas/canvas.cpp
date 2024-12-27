/**
 * @file canvas.cpp
 * @author Ethan Van Ruyskensvelde (Main developper)
 * @brief Define the class Canvas that will be used to draw all the pieces of
 * the game
 * @date 24/11/2024
 *
 */

#include "canvas.hpp"
#include "../piece/ball_ui.hpp"
#include "../piece/bonus_pill_ui.hpp"
#include "../piece/brick_ui.hpp"
#include "../piece/racket_ui.hpp"
#include "../piece/wall_ui.hpp"

Canvas::Canvas(shared_ptr<GameBoard> gameBoard, ALLEGRO_FONT *fontBrick)
    : gameBoard_(gameBoard), fontBrick_(fontBrick) {};

void Canvas::draw() {
    for (auto &border : borders_) {
        WallUi wallUi{border->getBoundingBox().getCenter(),
                      static_cast<float>(border->getBoundingBox().getWidth()),
                      static_cast<float>(border->getBoundingBox().getHeight()),
                      COLOR_WHITE};
        wallUi.draw();
    }

    for (auto &brick : bricks_) {
        BrickUi brickUi{brick->getBoundingBox().getCenter(),
                        static_cast<float>(brick->getBoundingBox().getWidth()),
                        static_cast<float>(brick->getBoundingBox().getHeight()),
                        colorToAllegroColor(brick->getColor()), fontBrick_};
        brickUi.draw(*brick);
    }

    for (auto &bonusPill : bonusPills_) {
        BonusPillUi bonusPillUi{
            bonusPill->getPos(),
            static_cast<float>(bonusPill->getBoundingBox().getWidth()),
            static_cast<float>(bonusPill->getBoundingBox().getHeight())};
        bonusPillUi.draw(*bonusPill);
    }

    for (auto &ball : balls_) {
        BallUi ballUi{ball->getPos(), static_cast<float>(ball->getRadius())};
        ballUi.draw();
    }

    RacketUi racketUi{racket_->getPos(),
                      static_cast<float>(racket_->getBoundingBox().getWidth()),
                      static_cast<float>(racket_->getBoundingBox().getHeight()),
                      COLOR_RED};
    racketUi.draw();
}
