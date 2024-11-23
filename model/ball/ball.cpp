#include "ball.hpp"

#include <cmath>
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
    Vec2 closestPoint = getClosestPoint(boundingBox); // F position

    Vec2 coordToClosestPoint{closestPoint - coord_}; // E to F

    double angleRad =
        atan2(closestPoint.y - coord_.y, closestPoint.x - coord_.x);

    std::cout << "angle: " << angleRad << std::endl;

    Vec2 radiusVec{coord_.x + radius_ * cos(angleRad), // G position
                   coord_.y + radius_ * sin(angleRad)};

    std::cout << "coordToClosestPoint: " << coordToClosestPoint << std::endl;

    std::cout << "radius vec : " << radiusVec << std::endl;

    Vec2 coordToRadiusVec = radiusVec - coord_;
    std::cout << "coordToRadiusVec: " << coordToRadiusVec << std::endl;

    // how much the ball is already inside the boundingBox
    Vec2 penetrationVec = coordToRadiusVec - coordToClosestPoint;

    std::cout << "penetrationVec: " << penetrationVec << std::endl;

    // BoundingBoxPosition boundingBoxPos =
    //     boundingBox.getPointPosition(closestPoint);

    // if (std::holds_alternative<BoundingBoxCorner>(boundingBoxPos)) {
    //     BoundingBoxCorner corner =
    //     std::get<BoundingBoxCorner>(boundingBoxPos); switch (corner) { case
    //     BoundingBoxCorner::TopLeft:
    //         std::cout << "TopLeft corner\n";
    //         coord_.x -= penetrationVec.x;
    //         coord_.y += penetrationVec.y;
    //         break;
    //     case BoundingBoxCorner::BottomLeft:
    //         coord_ -= penetrationVec;
    //         std::cout << "BottomLeft corner\n";
    //         break;
    //     case BoundingBoxCorner::TopRight:
    //         coord_ += (penetrationVec);
    //         std::cout << "TopRight corner\n";
    //         break;
    //     case BoundingBoxCorner::BottomRight:
    //         coord_.x += penetrationVec.x;
    //         coord_.y -= penetrationVec.y;
    //         std::cout << "BottomRight corner\n";
    //         break;
    //     }
    // } else if (std::holds_alternative<BoundingBoxEdge>(boundingBoxPos)) {
    //     BoundingBoxEdge edge = std::get<BoundingBoxEdge>(boundingBoxPos);
    //     switch (edge) {
    //     case BoundingBoxEdge::Right:
    //         coord_.x += penetrationVec.x;
    //         std::cout << "Right edge\n";
    //         break;
    //     case BoundingBoxEdge::Left:
    //         coord_.x -= penetrationVec.x;
    //         std::cout << "Left edge\n";
    //         break;
    //     case BoundingBoxEdge::Up:
    //         coord_.y += penetrationVec.y;
    //         std::cout << "Up edge\n";
    //         break;
    //     case BoundingBoxEdge::Down:
    //         coord_.y -= penetrationVec.y;
    //         std::cout << "Down edge\n";
    //         break;
    //     }
    // }
}

Vec2 Ball::getClosestPoint(const BoundingBox &boundingBox) const {
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
