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
#include "../piece/lazer_ui.hpp"
#include "../piece/racket_ui.hpp"
#include "../piece/wall_ui.hpp"

Canvas::Canvas(shared_ptr<GameBoard> gameBoard, ALLEGRO_FONT *fontBrick)
    : gameBoard_(gameBoard), fontBrick_(fontBrick) {};

void Canvas::draw() {
    for (auto &border : borders_) {
        WallUi wallUi{border->getCenter(),
                      static_cast<float>(border->getWidth()),
                      static_cast<float>(border->getHeight()), COLOR_WHITE};
        wallUi.draw();
    }

    for (auto &brick : bricks_) {
        BrickUi brickUi{brick->getCenter(),
                        static_cast<float>(brick->getWidth()),
                        static_cast<float>(brick->getHeight()),
                        colorToAllegroColor(brick->getColor())};
        brickUi.draw(*brick, fontBrick_);
    }

    for (auto &bonusPill : bonusPills_) {
        BonusPillUi bonusPillUi{
            bonusPill->getCenter(), static_cast<float>(bonusPill->getWidth()),
            static_cast<float>(bonusPill->getHeight()), *bonusPill};
        bonusPillUi.draw();
    }

    for (auto &lazer : lazers_) {
        LazerUi lazerUi{
            lazer->getPos(),
            static_cast<float>(lazer->getBoundingBox().getWidth()),
            static_cast<float>(lazer->getBoundingBox().getHeight())};
        lazerUi.draw();
    }

    for (auto &ball : balls_) {
        BallUi ballUi{ball->getCenter(), static_cast<float>(ball->getRadius())};
        ballUi.draw();
    }

    RacketUi racketUi{racket_->getCenter(),
                      static_cast<float>(racket_->getWidth()),
                      static_cast<float>(racket_->getHeight()), COLOR_RED};
    racketUi.draw();
}
