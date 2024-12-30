#include "lazer.hpp"

Lazer::Lazer(const Vec2 &center)
    : RectangleShape{center, LAZER_WIDTH, LAZER_HEIGHT}, bonusType_{bonusType},
      descentSpeed_{LAZER_SPEED} {}

void Lazer::update(double deltaTime) {
    setCenter({getCenter().x, getCenter().y - LAZER_SPEED * deltaTime});
}
