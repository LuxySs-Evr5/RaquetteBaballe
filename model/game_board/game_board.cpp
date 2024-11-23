#include "game_board.hpp"

#include <vector>

void GameBoard::update(double deltaTime) {
    for (auto ball : balls) {
        std::cout << "coord: " << ball->getCoordinate() << std::endl;

        for (auto brickIt = bricks.begin(); brickIt != bricks.end();) {

            if (ball->checkCollision((*brickIt)->getBoundingBox())) {
                ball->repositionOutsideOf((*brickIt)->getBoundingBox());
                ball->bounce((*brickIt)->getBoundingBox());
                (*brickIt)->hit(); // decrement its durability
                if ((*brickIt)
                        ->isDestroyed()) { // erase brick if it is destroyed
                    brickIt = bricks.erase(brickIt);
                }
                // NOTE: do not break here since we could have a bounce against
                // two bricks at the same time (board's corners)
            } else {
                brickIt++;
            }
        }

        ball->update(deltaTime);
        std::cout << std::endl;
    }
}
