#include "ball.hpp"

#include <iostream>

Ball::Ball(Vec2 coord, Vec2 directionVec, double radius, double speed)
    : coord_{coord}, dirVec_{directionVec.normalize()}, radius_{radius},
      speed_{speed} {}

Vec2 Ball::getCoordinate() { return coord_; }
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

void Ball::repositionOutsideOf(const BoundingBox &boundingBox) {
    // TODO: write a comment to explain how this works
    Vec2 closestVec2 = getClosestPoint(boundingBox);

    // TODO: find better names than vx vy (used the ones from the image)
    double vx = closestVec2.x - coord_.x;
    double vy = closestVec2.y - coord_.y;

    double toMoveX = radius_ - vx;
    double toMoveY = radius_ - vy;

    std::cout << "toMoveX: " << toMoveX << std::endl;
    std::cout << "toMoveY: " << toMoveY << std::endl;

    coord_.x -= toMoveX;
    coord_.y -= toMoveY;
}

Vec2 Ball::getClosestPoint(const BoundingBox &boundingBox) const {
    // NOTE: this is where you stopped working last time
    Vec2 boundingBoxHalfExtents{boundingBox.getWidth() / 2,
                                boundingBox.getHeight() / 2};

    Vec2 distance = coord_ - boundingBox.getCenter();

    Vec2 clamped =
        distance.clamped(-boundingBoxHalfExtents, boundingBoxHalfExtents);

    Vec2 closestPoint = clamped + boundingBox.getCenter();

    std::cout << "closestPoint= " << closestPoint << std::endl;

    return closestPoint;
}

bool Ball::hasReached(const Vec2 &point) const {
    double deltaX = point.x - coord_.x;
    double deltaY = point.y - coord_.y;

    return Vec2{deltaX, deltaY}.getModule() <= radius_;
}

bool Ball::checkCollision(const BoundingBox &boundingBox) const {
    Vec2 closestVec2 = getClosestPoint(boundingBox);

    return hasReached(closestVec2);
}
