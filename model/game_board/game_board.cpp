#include "game_board.hpp"

#include <vector>

void GameBoard::update(double deltaTime) {
    for (auto ball : balls) {
        std::cout << "coord: " << ball->getCoordinate() << std::endl;

        for (auto brickIt = bricks.begin(); brickIt != bricks.end();) {

            std::cout << "brick : " << (*brickIt)->getBoundingBox().getTopLeft()
                      << " " << (*brickIt)->getBoundingBox().getBottomRight()
                      << std::endl;

            std::cout << "ball : " << ball->getCoordinate() << std::endl;

            if (ball->checkCollision((*brickIt)->getBoundingBox())) {
                std::cout << "overlapping, repositionning..." << std::endl;

                const BoundingBox &boundingbox = (*brickIt)->getBoundingBox();
                std::cout << "coucou\n";
                ball->collide(boundingbox);

                std::cout << "repositionned at " << ball->getCoordinate()
                          << std::endl;

                (*brickIt)->hit(); // decrement its durability

                if ((*brickIt)
                        ->isDestroyed()) { // erase brick if it is destroyed

                    std::cout << "erasing rectangle " << std::endl;
                    brickIt = bricks.erase(brickIt);
                }
            } else {
                brickIt++;
            }
        }
        ball->update(deltaTime);
        std::cout << std::endl;
    }
}
