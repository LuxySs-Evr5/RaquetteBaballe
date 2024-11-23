#include "model.hpp"
#include "bounding_box/bounding_box.hpp"

#include <iostream>

void Model::update(double deltaTime) {
    for (auto ball : balls) {
        for (auto brickIt = bricks.begin(); brickIt != bricks.end();) {
            std::cout << "ball: " << ball->getCoordinate() << std::endl;

            if (ball->checkCollision((*brickIt)->getBoundingBox())) {
                std::cout << "overlapping, repositionning..." << std::endl;

                const BoundingBox &bd = (*brickIt)->getBoundingBox();
                ball->collide(bd);

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
