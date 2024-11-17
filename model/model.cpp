#include "model.hpp"

#include <iostream>

void Model::update(double deltaTime) {
    for (auto ball : balls) {
        std::cout << "x = " << ball->getCoordinate().x
                  << " y =" << ball->getCoordinate().y << std::endl;
        for (auto it = bricks.begin(); it != bricks.end();) {
            Point nearestPoint =
                (*it)->getNearestPointFrom(ball->getCoordinate());
            if (ball->hasReached(nearestPoint)) {
                std::cout << "erasing rectangle containing (" << nearestPoint.x
                          << ", " << nearestPoint.y << ")" << std::endl;
                it = bricks.erase(it);
            } else {
                it++;
            }
        }
        ball->update(deltaTime);
    }
}
