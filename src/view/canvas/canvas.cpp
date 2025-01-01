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
    for (auto &border : gameBoard_->getBorders()) {
        WallUi wallUi{border->getCenter(),
                      static_cast<float>(border->getWidth()),
                      static_cast<float>(border->getHeight()), COLOR_WHITE};
        wallUi.draw();
    }

    for (auto &brick : gameBoard_->getBricks()) {
        BrickUi brickUi{brick->getCenter(),
                        static_cast<float>(brick->getWidth()),
                        static_cast<float>(brick->getHeight()),
                        colorToAllegroColor(brick->getColor()),
                        brick->getDurability(),
                        brick->getBonusType()};
        brickUi.draw(fontBrick_);
    }

    for (auto &bonusPill : gameBoard_->getDescendingBonuses()) {
        BonusPillUi bonusPillUi{bonusPill->getCenter(),
                                static_cast<float>(bonusPill->getWidth()),
                                static_cast<float>(bonusPill->getHeight()),
                                bonusPill->getBonusType()};
        bonusPillUi.draw();
    }

    for (auto &lazer : gameBoard_->getLazers()) {
        LazerUi lazerUi{lazer->getCenter(),
                        static_cast<float>(lazer->getWidth()),
                        static_cast<float>(lazer->getHeight())};
        lazerUi.draw();
    }

    for (auto &ball : gameBoard_->getBalls()) {
        BallUi ballUi{ball->getCenter(), static_cast<float>(ball->getRadius())};
        ballUi.draw();
    }

    RacketUi racketUi{gameBoard_->getRacket().getCenter(),
                      static_cast<float>(gameBoard_->getRacket().getWidth()),
                      static_cast<float>(gameBoard_->getRacket().getHeight()),
                      COLOR_RED};
    racketUi.draw();
}
