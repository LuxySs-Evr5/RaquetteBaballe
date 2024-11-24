#include "game_board.hpp"
#include <memory>
#include <variant>

using BrickIt = std::vector<std::shared_ptr<Brick>>::const_iterator;
using BorderIt = std::vector<std::shared_ptr<Border>>::const_iterator;

std::variant<BrickIt, BorderIt> GameBoard::findNextCollision(Ball &ball) {

    std::variant<BrickIt, BorderIt> closestCollision = bricks_.end();
    double distanceClosestCollision = std::numeric_limits<double>::max();

    // Helper lambda function
    auto checkCollisions = [&](auto &elements, auto &closestCollision) {
        for (auto it = elements.begin(); it != elements.end(); ++it) {
            if (ball.checkCollision((*it)->getBoundingBox())) {
                double distanceCurrentCollision =
                    ball.getUnidirectionalPenetration((*it)->getBoundingBox())
                        .getModule();

                if (distanceCurrentCollision < distanceClosestCollision) {
                    closestCollision = it;
                    distanceClosestCollision = distanceCurrentCollision;
                }
            }
        }
    };

    checkCollisions(bricks_, closestCollision);
    checkCollisions(borders_, closestCollision);

    // TODO: add the same for racket here

    return closestCollision;
}

void GameBoard::update(double deltaTime) {
    for (auto ball : balls_) {
        std::cout << "coord: " << ball->getCoordinate() << std::endl;

        // collide with racket

        bool collided;
        do {
            auto collidingObject = findNextCollision(*ball);

            // Check if collision with brick
            if (std::holds_alternative<BrickIt>(collidingObject)) {
                auto brickIt = std::get<BrickIt>(collidingObject);
                if (brickIt != bricks_.end()) {
                    std::cout << "Collision with a brick!" << std::endl;

                    ball->collide(*brickIt->get());
                    (*brickIt)->hit(); // decrement its durability

                    if ((*brickIt)->isDestroyed()) { // erase it if destroyed
                        std::cout << "erasing brick " << std::endl;
                        bricks_.erase(brickIt);
                    }
                } else {
                    std::cout << "No collision found." << std::endl;
                    break;
                }
            } // Check if collision with border
            else if (std::holds_alternative<BorderIt>(collidingObject)) {
                auto borderIt = std::get<BorderIt>(collidingObject);
                if (borderIt != borders_.end()) {
                    std::cout << "Collision with a border!" << std::endl;
                    ball->collide(*borderIt->get());
                }
            }

            collided = true;

            std::cout << "repositionned at " << ball->getCoordinate()
                      << std::endl;

            std::cout << "hitting the brick" << std::endl;
        } while (collided);

        ball->update(deltaTime);
        std::cout << std::endl;
    }
}
