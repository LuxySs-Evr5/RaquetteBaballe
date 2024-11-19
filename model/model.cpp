#include "model.hpp"

#include <iostream>
#include <memory>

void Model::update(double deltaTime) {
    // auto brick = Brick::makeBrick(Color::red, Rectangle{Point{2, 1}, 4, 2});
    // auto brick = Brick::makeBrick(Color::red, Rectangle{{4, 0}, {6, 4}});

    for (auto ball : balls) {
        for (auto it = bricks.begin(); it != bricks.end();) {
            std::shared_ptr<Brick> brick = *it;

            std::cout << "brick : " << brick->getRectangle().getTopLeft() << " "
                      << brick->getRectangle().getBottomRight() << std::endl;

            std::cout << "ball : " << ball->getCoordinate() << std::endl;

            if (ball->checkCollision(brick->getRectangle())) {
                std::cout << "overlapping, repositionning..." << std::endl;

                ball->repositionOutsideOf(brick->getRectangle());

                std::cout << "repositionned at " << ball->getCoordinate()
                          << std::endl;

                // if (false /* vertical bounce */) {
                //     std::cout << "vertical bounce " << std::endl;
                //     ball->bounce(BounceType::vertical);
                // } // could be both at once if we hit a corner?
                // if (false /* horizontal bounce */) {
                //     std::cout << "horizontal bounce " << std::endl;
                //     ball->bounce(BounceType::horizontal);
                // }

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
