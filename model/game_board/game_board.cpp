#include "game_board.hpp"

void GameBoard::update(double deltaTime) {
    for (auto ball : balls_) {
        std::cout << "coord: " << ball->getCoordinate() << std::endl;

        bool colliding;
        do {
            auto closestBrickIt = ball->findClosestBrick(bricks_);

            if (closestBrickIt == bricks_.end()) {
                std::cerr << "No bricks left to check" << std::endl;
                break;
            }

            colliding =
                ball->checkCollision((*closestBrickIt)->getBoundingBox());

            if (colliding) {
                std::cout << "collision detected..." << std::endl;

                ball->collide((*closestBrickIt)->getBoundingBox());

                std::cout << "repositionned at " << ball->getCoordinate()
                          << std::endl;

                (*closestBrickIt)->hit(); // decrement its durability

                std::cout << "hitting the brick" << std::endl;
                if ((*closestBrickIt)
                        ->isDestroyed()) { // erase brick if it is destroyed

                    std::cout << "erasing brick " << std::endl;
                    bricks_.erase(closestBrickIt);
                }
            }
        } while (colliding);

        for (const BoundingBox &border : borders_) {
            if (ball->checkCollision(border)) {
                std::cout << "colliding map boarder" << std::endl;
                ball->collide(border);
                std::cout << "repositionned at " << ball->getCoordinate()
                          << std::endl;
            }
        }

        ball->update(deltaTime);
        std::cout << std::endl;
    }
}
