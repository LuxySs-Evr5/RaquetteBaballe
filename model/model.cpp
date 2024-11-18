#include "model.hpp"

#include <iostream>
#include <memory>

void Model::update(double deltaTime) {
    for (auto ball : balls) {
        std::cout << "x = " << ball->getCoordinate().x
                  << " y =" << ball->getCoordinate().y << std::endl;
        for (auto it = bricks.begin(); it != bricks.end();) {
            std::shared_ptr<Brick> brick = *it;

            if (false /*ball is in brick's bouncing-area*/) {
                if (false /* vertical bounce */) {
                    std::cout << "vertical bounce " << std::endl;
                    ball->bounce(BounceType::vertical);
                } // could be both at once if we hit a corner?
                if (false /* horizontal bounce */) {
                    std::cout << "horizontal bounce " << std::endl;
                    ball->bounce(BounceType::horizontal);
                }

                brick->hit(); // decrement its durability

                if (brick->isDestroyed()) { // erase brick if it is destroyed
                    it = bricks.erase(it);
                }

                break; // we don't have to check for other bricks if we
                       // have already found the one we have hit
            } else {
                it++;
            }
        }
        ball->update(deltaTime);
    }
}
