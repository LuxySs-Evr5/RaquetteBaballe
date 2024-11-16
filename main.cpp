#include "ball.hpp"
#include <iostream>
#include <unistd.h>

int main() {
    Point coord{0, 0};
    Point dir{1, 1};

    Ball b{coord, dir};

    for (int i = 0; i < 20; i++) {
        Point coord = b.getCoordinate();
        std::cout << "(" << coord.x << ", " << coord.y << ")" << std::endl;

        if (i == 2) {
            b.bounce(BounceType::vertical);
        }

        if (i == 4) {
            b.setSpeed(2);
        }

        b.update();
    }
}
