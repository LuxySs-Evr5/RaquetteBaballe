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

double clamp(double value, double min, double max) {
    return std::max(min, std::min(max, value));
}

void Ball::repositionOutsideOf(const Rectangle &rectangle) {
    // TODO: write a comment to explain how this works
    Vec2 closestVec2 = getClosestVec2(rectangle);

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

Vec2 Ball::getClosestVec2(const Rectangle &rectangle) const {
    Vec2 rectCenter = rectangle.getCenter();
    size_t rectCenterX = rectCenter.x;
    size_t rectCenterY = rectCenter.y;

    // NOTE: this is where you stopped working last time
    // TODO: add operator- & merge Vec2 with Vec2
    Vec2 distance = coord_ - rectangle.getCenter();
    // distance.clamp(rectangle);

    //

    // this is wrong
    double halfWidth = static_cast<double>(rectangle.getWidth()) / 2;
    double halfHeight = static_cast<double>(rectangle.getHeight()) / 2;
    double closestX =
        clamp(coord_.x, rectCenterX - halfWidth, rectCenterX + halfWidth);
    double closestY =
        clamp(coord_.y, rectCenterY - halfHeight, rectCenterY + halfHeight);

    std::cout << "closestVec2=(" << closestX << ", " << closestY << ")"
              << std::endl;

    return Vec2{closestX, closestY};
}

bool Ball::hasReached(const Vec2 &point) const {
    double deltaX = point.x - coord_.x;
    double deltaY = point.y - coord_.y;

    return Vec2{deltaX, deltaY}.getModule() <= radius_;
}

bool Ball::checkCollision(const Rectangle &rectangle) const {
    Vec2 closestVec2 = getClosestVec2(rectangle);

    return hasReached(closestVec2);
}
