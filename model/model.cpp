#include "model.hpp"

#include <iostream>
#include <memory>

void Model::update(double deltaTime) {
    for (auto ball : balls) {
        std::cout << "x = " << ball->getCoordinate().x
                  << " y =" << ball->getCoordinate().y << std::endl;
        for (auto it = bricks.begin(); it != bricks.end();) {
            std::shared_ptr<Brick> brick = *it;

            Point nearestPoint =
                brick->getNearestPointFrom(ball->getCoordinate());

            if (ball->hasReached(nearestPoint)) {
                // if so, erase the brick
                std::cout << "reached rectangle containing (" << nearestPoint.x
                          << ", " << nearestPoint.y << ")" << std::endl;

                brick->hit(); // decrement it durability

                if (brick->isDestroyed()) { // erase de brick if it is destroyed
                    it = bricks.erase(it);
                }

                // TODO: bounce according to the BounceType
                // must detect the BounceType
                // Need getters for TopLeft and BottomRight coordinates
                Point ballCenter = ball->getCoordinate();
                Point topLeft = brick->getTopLeft();
                Point bottomRight = brick->getBottomRight();

                unsigned dist_to_left = abs(ballCenter.x - topLeft.x);
                unsigned dist_to_right = abs(ballCenter.x - bottomRight.x);
                unsigned dist_to_top = abs(ballCenter.y - topLeft.y);
                unsigned dist_to_bottom = abs(ballCenter.y - bottomRight.y);

                unsigned minHorizontalDist =
                    std::min(dist_to_left, dist_to_right);
                unsigned minVerticalDist =
                    std::min(dist_to_top, dist_to_bottom);

                if (minHorizontalDist <= minVerticalDist) {
                    std::cout << "horizontal bounce " << std::endl;
                    ball->bounce(BounceType::horizontal);
                } // could be both at once if we hit a corner?
                if (minVerticalDist <= minHorizontalDist) {
                    std::cout << "vertical bounce " << std::endl;
                    ball->bounce(BounceType::vertical);
                }

            } else {
                it++;
            }
        }
        ball->update(deltaTime);
    }
}
