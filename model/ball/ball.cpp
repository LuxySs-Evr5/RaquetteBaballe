#include "ball.hpp"

#include "../bounding_box/bounding_box.hpp"

#include <cmath>
#include <iostream>

using Point = Vec2;

Ball::Ball(Vec2 coord, Vec2 directionVec, double radius, double speed)
    : coord_{coord}, dirVec_{directionVec.normalize()}, radius_{radius},
      speed_{speed} {}

Vec2 Ball::getCoordinate() { return coord_; }
void Ball::setSpeed(unsigned speed) { speed_ = speed; };
void Ball::setDirection(const Vec2 &vec) { dirVec_ = vec; }

void Ball::update(double deltaTime) {
    prevCoord_ = coord_;
    coord_ += (dirVec_ * speed_ * deltaTime);
}

// NOTE: this only does the direction vector part of the bounce
// actual bounce logic is in collide function
void Ball::bounce(const BoundingBox &boundingBox) {
    Point closestPoint = getClosestPoint(boundingBox);
    BounceType bounceType = boundingBox.getBounceType(closestPoint);

    if (bounceType == BounceType::Horizontal) {
        dirVec_.y = -dirVec_.y;
    }
    if (bounceType == BounceType::Vertical) {
        dirVec_.x = -dirVec_.x;
    } else if (bounceType == BounceType::Corner) {
        dirVec_.y = -dirVec_.y;
        dirVec_.x = -dirVec_.x;
    }
}

void Ball::collide(const BoundingBox &boundingBox) {
    Vec2 UnidirectionalPenetration = getUnidirectionalPenetration(boundingBox);

    Point closestPoint = getClosestPoint(boundingBox);
    BounceType bounceType = boundingBox.getBounceType(closestPoint);

    Vec2 bidirectionalPenetration;
    Vec2 changeBetweenLastUpdate{coord_ - prevCoord_};
    std::cout << "changeBetweenLastUpdate: " << changeBetweenLastUpdate
              << std::endl;

    double penetrationRate = 1; // Default to prevent 0 division
    if (bounceType == BounceType::Horizontal
        and (changeBetweenLastUpdate.y != 0)) {
        penetrationRate =
            UnidirectionalPenetration.y / changeBetweenLastUpdate.y;

    } else if (bounceType == BounceType::Vertical
               or bounceType == BounceType::Corner
                      and changeBetweenLastUpdate.x != 0) {
        penetrationRate =
            UnidirectionalPenetration.x / changeBetweenLastUpdate.x;
    }

    bidirectionalPenetration = changeBetweenLastUpdate * penetrationRate;

    coord_ -= bidirectionalPenetration;

    bounce(boundingBox);

    // add back what the distance that the ball should have gone while it was
    // going inside the rectangle
    coord_ += dirVec_ * bidirectionalPenetration.getModule();
}

Vec2 Ball::getUnidirectionalPenetration(const BoundingBox &boundingBox) const {
    // TODO: write a comment to explain how this works
    Point closestPoint = getClosestPoint(
        boundingBox); // Closest point from the ball's center on the rectangle

    Vec2 coordToClosestPoint{
        closestPoint - coord_}; // Vector from ball's center to closest point

    double angleRad =
        atan2(closestPoint.y - coord_.y,
              closestPoint.x - coord_.x); // Angle between closestPoint and the
                                          // 0 degree from the circle's center

    // The point of the circle that is most inscribed in the rectangle
    Point pointInRectangle{coord_.x + radius_ * cos(angleRad),
                           coord_.y + radius_ * sin(angleRad)};

    // Vector between from ball's center to pointInRectangle
    Vec2 coordToPointInRectangle = pointInRectangle - coord_;

    // Vector from closestPoint to pointInRectangle (monodirectional penetration
    // vector)
    Vec2 MonoDirectionalPenetrationVec =
        coordToPointInRectangle - coordToClosestPoint;

    return MonoDirectionalPenetrationVec;
}

Vec2 Ball::getClosestPoint(const BoundingBox &boundingBox) const {
    Vec2 boundingBoxHalfExtents{boundingBox.getWidth() / 2,
                                boundingBox.getHeight() / 2};

    Vec2 distance = coord_ - boundingBox.getCenter();

    Vec2 clamped =
        distance.clamped(-boundingBoxHalfExtents, boundingBoxHalfExtents);

    Vec2 closestPoint = clamped + boundingBox.getCenter();

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
