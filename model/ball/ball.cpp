#include "ball.hpp"

#include <iostream>

Ball::Ball(Point coord, Vec2 directionVec, double radius, double speed)
    : coord_{coord}, dirVec_{directionVec.normalize()}, radius_{radius},
      speed_{speed} {}

Point Ball::getCoordinate() { return coord_; }
void Ball::setSpeed(unsigned speed) { speed_ = speed; };
void Ball::setDirectionX(int x) { dirVec_.x = x; }
void Ball::setDirectionY(int y) { dirVec_.y = y; }

void Ball::update(double deltaTime) {
    coord_.x += dirVec_.x * speed_ * deltaTime;
    coord_.y += dirVec_.y * speed_ * deltaTime;
}

void Ball::bounce(BounceType bounceType) {
    // technically could have both at once, e.g., brick corners
    if (bounceType == BounceType::horizontal) {
        dirVec_.y = -dirVec_.y;
    }
    if (bounceType == BounceType::vertical) {
        dirVec_.x = -dirVec_.x;
    }
}

float clamp(float value, float min, float max) {
    return std::max(min, std::min(max, value));
}

Point Ball::getClosestPoint(const Rectangle &rectangle) const {
    size_t rectX = rectangle.getCenter().x;
    size_t rectY = rectangle.getCenter().y;

    size_t halfWidth = rectangle.getWidth() / 2;
    size_t halfHeight = rectangle.getHeight() / 2;

    size_t closestX = clamp(coord_.x, rectX - halfWidth, rectX + halfWidth);
    size_t closestY = clamp(coord_.y, rectY - halfHeight, rectY + halfHeight);

    return Point{closestX, closestY};
}

bool Ball::hasReached(const Point &point) const {
    int deltaX = point.x - coord_.x;
    int deltaY = point.y - coord_.y;

    return Vec2{deltaX, deltaY}.getModule() <= radius_;
}

bool Ball::checkCollision(const Rectangle &rectangle) const {
    Point closestPoint = getClosestPoint(rectangle);

    std::cout << "closestPoint=(" << closestPoint.x << ", " << closestPoint.y
              << ")" << std::endl;

    return hasReached(closestPoint);
}
