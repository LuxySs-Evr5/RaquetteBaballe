#include "model.hpp"

#include <iostream>

void Model::update(double deltaTime) {
    for (auto ball : balls) {
        std::cout << "x = " << ball->getCoordinate().x
                  << " y =" << ball->getCoordinate().y << std::endl;
        ball->update(deltaTime);
        for (auto it = bricks.begin(); it != bricks.end();) {
            if (ball->getCoordinate() == (*it)->getCoordinate()) {
                std::cout << "erasing " << std::endl;
                it = bricks.erase(it);
            } else {
                it++;
            }
        }
    }
}
