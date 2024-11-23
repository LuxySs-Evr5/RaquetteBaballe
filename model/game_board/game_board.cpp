#include "game_board.hpp"

#include <vector>

void GameBoard::update(double deltaTime) {
    for (auto ball : balls_) {
        std::cout << "coord: " << ball->getCoordinate() << std::endl;

        for (auto brickIt = bricks_.begin(); brickIt != bricks_.end();) {

            std::cout << "brick : " << (*brickIt)->getBoundingBox().getTopLeft()
                      << " " << (*brickIt)->getBoundingBox().getBottomRight()
                      << std::endl;

            if (ball->checkCollision((*brickIt)->getBoundingBox())) {
                std::cout << "overlapping, repositionning..." << std::endl;

                ball->collide((*brickIt)->getBoundingBox());

                std::cout << "repositionned at " << ball->getCoordinate()
                          << std::endl;

                (*brickIt)->hit(); // decrement its durability

                if ((*brickIt)
                        ->isDestroyed()) { // erase brick if it is destroyed

                    std::cout << "erasing rectangle " << std::endl;
                    brickIt = bricks_.erase(brickIt);
                }
            } else {
                brickIt++;
            }
        }

        for (const BoundingBox &border : borders_) {
            if (ball->checkCollision(border)) {
                std::cout << "colliding map boarder" << std::endl;
                std::cout << "overlapping, repositionning..." << std::endl;
                ball->collide(border);
                std::cout << "repositionned at " << ball->getCoordinate()
                          << std::endl;
            }
        }

        ball->update(deltaTime);
        std::cout << std::endl;
    }
}
