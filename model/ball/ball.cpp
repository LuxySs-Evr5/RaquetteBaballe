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

double clamp(double value, double min, double max) {
    return std::max(min, std::min(max, value));
}

Point Ball::getClosestPoint(const Rectangle &rectangle) const {
    Point rectCenter = rectangle.getCenter();
    size_t rectCenterX = rectCenter.x;
    size_t rectCenterY = rectCenter.y;

    double halfWidth = static_cast<double>(rectangle.getWidth()) / 2;
    double halfHeight = static_cast<double>(rectangle.getHeight()) / 2;

    double closestX =
        clamp(coord_.x, rectCenterX - halfWidth, rectCenterX + halfWidth);
    double closestY =
        clamp(coord_.y, rectCenterY - halfHeight, rectCenterY + halfHeight);

    std::cout << "closestPoint=(" << closestX << ", " << closestY << ")"
              << std::endl;

    return Point{static_cast<size_t>(closestX), static_cast<size_t>(closestY)};
}

bool Ball::hasReached(const Point &point) const {
    int deltaX = point.x - coord_.x;
    int deltaY = point.y - coord_.y;

    return Vec2{deltaX, deltaY}.getModule() <= radius_;
}

bool Ball::checkCollision(const Rectangle &rectangle) const {
    Point closestPoint = getClosestPoint(rectangle);

    return hasReached(closestPoint);
}
