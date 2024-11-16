#include "ball.hpp"

Ball::Ball(Point coord, Point direction, unsigned speed)
    : coord_{coord}, direction_{direction}, speed_{speed} {}

Point Ball::getCoordinate() { return coord_; }
void Ball::setSpeed(unsigned speed) { speed_ = speed; };
void Ball::setDirection(Point newDirection) { direction_ = newDirection; }

void Ball::update() {
    coord_.x += direction_.x * speed_;
    coord_.y += direction_.y * speed_;
}

void Ball::bounce(BounceType bounceType) {
    if (bounceType == BounceType::horizontal) {
        direction_.y = -direction_.y;
    } else if (bounceType == BounceType::vertical) {
        direction_.x = -direction_.x;
    }
}
