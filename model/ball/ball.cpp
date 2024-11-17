#include "ball.hpp"

Ball::Ball(Point coord, Point direction, double radius, double speed)
    : coord_{coord}, direction_{direction}, radius_{radius}, speed_{speed} {}

Point Ball::getCoordinate() { return coord_; }
void Ball::setSpeed(unsigned speed) { speed_ = speed; };
void Ball::setDirection(Point newDirection) { direction_ = newDirection; }

void Ball::update(double deltaTime) {
    coord_.x += direction_.x * speed_ * deltaTime;
    coord_.y += direction_.y * speed_ * deltaTime;
}

void Ball::bounce(BounceType bounceType) {
    if (bounceType == BounceType::horizontal) {
        direction_.y = -direction_.y;
    } else if (bounceType == BounceType::vertical) {
        direction_.x = -direction_.x;
    }
}

bool Ball::hasReached(Point point) {
    double deltaX = abs(point.x - coord_.x);
    double deltaY = abs(point.y - coord_.y);

    return std::sqrt(std::pow(deltaX, 2) + std::pow(deltaY, 2)) <= radius_;
}
