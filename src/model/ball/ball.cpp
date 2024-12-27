#include "ball.hpp"

#include "../../log/log.hpp"
#include "../bounceable/bounceable.hpp"
#include "../bounding_box/bounding_box.hpp"

#include <cmath>
#include <string>

// NOTE: this only does the direction vector part of the bounce
// actual bounce logic is in collide function
void Ball::bounce(const Bounceable &bounceable) {
    Vec2 closestPoint = getClosestPoint(bounceable.getBoundingBox());

    dirVec_ = bounceable.getDirVecAfterBounce(closestPoint, dirVec_);
}

Vec2 Ball::getClosestPoint(const BoundingBox &boundingBox) const {
    Vec2 boundingBoxHalfExtents{boundingBox.getWidth() / 2,
                                boundingBox.getHeight() / 2};

    Vec2 distance = pos_ - boundingBox.getCenter();

    Vec2 clamped =
        distance.clamped(-boundingBoxHalfExtents, boundingBoxHalfExtents);

    Vec2 closestPoint = clamped + boundingBox.getCenter();

    return closestPoint;
}

bool Ball::hasReached(const Vec2 &point) const {
    double deltaX = point.x - pos_.x;
    double deltaY = point.y - pos_.y;
    return Vec2{deltaX, deltaY}.getModule() < radius_;
}

Ball::Ball(Vec2 pos, Vec2 directionVec, double radius, double speed)
    : pos_{pos}, dirVec_{directionVec.normalize()}, radius_{radius},
      speed_{speed} {}

double Ball::getRadius() const noexcept { return radius_; }

const Vec2 &Ball::getPos() const noexcept { return pos_; }

const Vec2 &Ball::getDirvec() const noexcept { return dirVec_; }

void Ball::setSpeed(unsigned speed) { speed_ = speed; };

void Ball::setDirVec(const Vec2 &vec) { dirVec_ = vec; }

Vec2 Ball::getUnidirectionalPenetration(const BoundingBox &boundingBox) const {
    Vec2 closestPoint =
        getClosestPoint(boundingBox); // Closest point from the ball's center,
                                      // on the bounding-box's edge

    Vec2 posToClosestPoint{
        closestPoint - pos_}; // Vector from ball's center to closest point

    double angleRad =
        atan2(closestPoint.y - pos_.y,
              closestPoint.x - pos_.x); // Angle between closestPoint and the
                                        // 0 degree from the circle's center

    // The point on the circle in the direction of the closestPoint
    Vec2 pointInBoundingBox{pos_.x + radius_ * cos(angleRad),
                            pos_.y + radius_ * sin(angleRad)};

    return pointInBoundingBox - closestPoint;
}

bool Ball::checkCollision(const BoundingBox &boundingBox) const {
    Vec2 closestVec2 = getClosestPoint(boundingBox);

    return hasReached(closestVec2);
}

void Ball::collide(const Bounceable &bounceable) {
    Log::get().addMessage(Log::LogType::DirVec, getDirvec());

    Log::get().addMessage(
        Log::LogType::CollidingObject,
        std::string{"topLeft: "}
            + std::string{bounceable.getBoundingBox().getTopLeft()});
    Log::get().addMessage(
        Log::LogType::CollidingObject,
        std::string{"bottomRight: "}
            + std::string{bounceable.getBoundingBox().getBottomRight()});

    Vec2 unidirectionalPenetration =
        getUnidirectionalPenetration(bounceable.getBoundingBox());
    Log::get().addMessage(Log::LogType::Unidirectional,
                          std::string{unidirectionalPenetration});

    Vec2 closestPoint = getClosestPoint(bounceable.getBoundingBox());
    Log::get().addMessage(Log::LogType::ClosestPoint,
                          std::string{closestPoint});

    BounceType bounceType = bounceable.getBounceType(closestPoint);
    Log::get().addMessage(Log::LogType::BounceType,
                          bounceTypeToString(bounceType));

    Vec2 changeBetweenLastUpdate{pos_ - prevPos_};
    Log::get().addMessage(Log::LogType::ChangeBetweenLastUpdate,
                          changeBetweenLastUpdate);

    double penetrationRate = 1; // Default to 1 to prevent 0-division
    if (((bounceType == BounceType::Horizontal)
         || (bounceType == BounceType::Corner))
        && (changeBetweenLastUpdate.y != 0)) {
        penetrationRate =
            unidirectionalPenetration.y / changeBetweenLastUpdate.y;

    } else if ((bounceType == BounceType::Vertical)
               && (changeBetweenLastUpdate.x != 0)) {
        penetrationRate =
            unidirectionalPenetration.x / changeBetweenLastUpdate.x;
    }
    Log::get().addMessage(Log::LogType::PenetrationRate,
                          std::to_string(penetrationRate));

    Vec2 bidirectionalPenetration = changeBetweenLastUpdate * penetrationRate;
    Log::get().addMessage(Log::LogType::Bidirectional,
                          bidirectionalPenetration);

    pos_ -= bidirectionalPenetration;

    bounce(bounceable);
    Log::get().addMessage(Log::LogType::DirVec,
                          std::string{"dirvec afterBounce: "}
                              + std::string{getDirvec()});

    // Add back the distance that the ball should have travelled instead of
    // going inside the bounding-box
    pos_ += dirVec_ * bidirectionalPenetration.getModule();
}

void Ball::update(double deltaTime) {
    prevPos_ = pos_;
    pos_ += (dirVec_ * speed_ * deltaTime);
}
