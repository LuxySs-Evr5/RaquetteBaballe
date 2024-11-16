#include "model.hpp"

#include <iostream>

void Model::run() {
    for (int i = 0; i < 10; i++) {
        for (auto ball : balls) {
            ball->update();
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
};
