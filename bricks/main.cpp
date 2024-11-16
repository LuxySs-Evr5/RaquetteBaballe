#include "brick.hpp"

#include <iostream>
#include <memory>

int main() {
    std::unique_ptr<Brick> someBrick =
        Brick::makeBrick(Color::red, Point{0, 0});

    someBrick->hit();
    std::cout << someBrick->isDestroyed() << std::endl;
}
