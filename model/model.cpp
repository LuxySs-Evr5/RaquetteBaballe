#include "model.hpp"

#include <iostream>
#include <memory>

void Model::update(double deltaTime) {
    for (auto ball : balls) {
        std::cout << "coord: " << ball->getCoordinate() << std::endl;

        for (auto it = bricks.begin(); it != bricks.end();) {
            std::shared_ptr<Brick> brick = *it;

            std::cout << "brick : " << brick->getBoundingBox().getTopLeft()
                      << " " << brick->getBoundingBox().getBottomRight()
                      << std::endl;

            std::cout << "ball : " << ball->getCoordinate() << std::endl;

            if (ball->checkCollision(brick->getBoundingBox())) {
                std::cout << "overlapping, repositionning..." << std::endl;

                ball->repositionOutsideOf(brick->getBoundingBox());

                std::cout << "repositionned at " << ball->getCoordinate()
                          << std::endl;

                ball->bounce(brick->getBoundingBox());

                brick->hit(); // decrement its durability

                if (brick->isDestroyed()) { // erase brick if it is destroyed
                    std::cout << "erasing rectangle " << std::endl;
                    it = bricks.erase(it);
                }

                // break; // we don't have to check for other bricks if we
                // have already found the one we have hit
            } else {
                it++;
            }
        }
        ball->update(deltaTime);
        std::cout << std::endl;
    }
}
