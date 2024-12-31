#include "lazer.hpp"
#include "../../global_variables.hpp"

Lazer::Lazer(const Vec2 &center)
    : RectangleShape{center, LAZER_WIDTH, LAZER_HEIGHT}, speed_{LAZER_SPEED} {}

void Lazer::update(double deltaTime) {
    setCenter({getCenter().x, getCenter().y + LAZER_SPEED * deltaTime});
}
