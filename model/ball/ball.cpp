#include "ball.hpp"

#include <iostream>

Ball::Ball(Point coord, Vec2 directionVec, double radius, double speed)
    : coord_{coord}, dirVec_{directionVec.normalize()}, radius_{radius},
      speed_{speed} {}

Point Ball::getCoordinate() { return coord_; }
void Ball::setSpeed(unsigned speed) { speed_ = speed; };
void Ball::setDirection(const Vec2 &vec) { dirVec_ = vec; }

void Ball::update(double deltaTime) {
    coord_ += (dirVec_ * speed_ * deltaTime);
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

void Ball::repositionOutsideOf(const Rectangle &rectangle) {
    // TODO: write a comment to explain how this works
    Point closestPoint = getClosestPoint(rectangle);

    // TODO: find better names than vx vy (used the ones from the image)
    double vx = closestPoint.x - coord_.x;
    double vy = closestPoint.y - coord_.y;

    double toMoveX = radius_ - vx;
    double toMoveY = radius_ - vy;

    std::cout << "toMoveX: " << toMoveX << std::endl;
    std::cout << "toMoveY: " << toMoveY << std::endl;

    coord_.x -= toMoveX;
    coord_.y -= toMoveY;
}

Point Ball::getClosestPoint(const Rectangle &rectangle) const {
    Point rectCenter = rectangle.getCenter();
    size_t rectCenterX = rectCenter.x;
    size_t rectCenterY = rectCenter.y;

    // NOTE: this is where you stopped working last time
    // TODO: add operator- & merge Vec2 with Point
    Vec2 distance = coord_ - rectangle.getCenter();
    distance.clamp(rectangle);

    //

    // this is wrong
    double halfWidth = static_cast<double>(rectangle.getWidth()) / 2;
    double halfHeight = static_cast<double>(rectangle.getHeight()) / 2;
    double closestX =
        clamp(coord_.x, rectCenterX - halfWidth, rectCenterX + halfWidth);
    double closestY =
        clamp(coord_.y, rectCenterY - halfHeight, rectCenterY + halfHeight);

    std::cout << "closestPoint=(" << closestX << ", " << closestY << ")"
              << std::endl;

    return Point{closestX, closestY};
}

bool Ball::hasReached(const Point &point) const {
    double deltaX = point.x - coord_.x;
    double deltaY = point.y - coord_.y;

    return Vec2{deltaX, deltaY}.getModule() <= radius_;
}

bool Ball::checkCollision(const Rectangle &rectangle) const {
    Point closestPoint = getClosestPoint(rectangle);

    return hasReached(closestPoint);
}
