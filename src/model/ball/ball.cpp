#include "ball.hpp"

#include "../../log/log.hpp"
#include "../bounceable/bounceable.hpp"

#include <cmath>
#include <string>

// NOTE: this only does the direction vector part of the bounce
// actual bounce logic is in collide function
void Ball::bounce(const Bounceable &bounceable) {
    Vec2 closestPoint = getClosestPoint(bounceable);

    dirVec_ = bounceable.getDirVecAfterBounce(closestPoint, dirVec_);
}

Vec2 Ball::getClosestPoint(const RectangleShape &rectangle) const {
    Vec2 rectangleHalfExtents{rectangle.getWidth() / 2,
                              rectangle.getHeight() / 2};

    Vec2 distance = center_ - rectangle.getCenter();

    Vec2 clamped =
        distance.clamped(-rectangleHalfExtents, rectangleHalfExtents);

    Vec2 closestPoint = clamped + rectangle.getCenter();

    return closestPoint;
}

bool Ball::hasReached(const Vec2 &point) const {
    double deltaX = point.x - center_.x;
    double deltaY = point.y - center_.y;
    return Vec2{deltaX, deltaY}.getModule() < radius_;
}

Ball::Ball(const Vec2 &center, Vec2 directionVec, double radius, double speed,
           bool isStuck)
    : center_{center}, dirVec_{directionVec.normalized()}, radius_{radius},
      speed_{speed}, isStuck_{isStuck} {}

double Ball::getRadius() const noexcept { return radius_; }

const Vec2 &Ball::getCenter() const noexcept { return center_; }

const Vec2 &Ball::getDirvec() const noexcept { return dirVec_; }

double Ball::getSpeed() const noexcept { return speed_; }

bool Ball::isStuck() const noexcept { return isStuck_; }

void Ball::setSpeed(double speed) { speed_ = speed; };

void Ball::setCenter(const Vec2 &center) { center_ = center; }

void Ball::setCenterX(double centerX) { center_.x = centerX; }

void Ball::setDirVec(const Vec2 &vec) { dirVec_ = vec.normalized(); }

void Ball::setIsStuck(bool isStuck) { isStuck_ = isStuck; }

Vec2 Ball::getSimplePenetrationVec(const RectangleShape &rectangleShape) const {
    Vec2 closestPoint =
        getClosestPoint(rectangleShape); // Closest point from the ball's
                                         // center, on the rectangleShape's edge

    Vec2 centerToClosestPoint{
        closestPoint - center_}; // Vector from ball's center to closest point

    double angleRad =
        atan2(closestPoint.y - center_.y,
              closestPoint.x - center_.x); // Angle between closestPoint and the
                                           // 0 degree from the circle's center

    // The point on the circle in the direction of the closestPoint
    Vec2 pointInRectangle{center_.x + radius_ * cos(angleRad),
                          center_.y + radius_ * sin(angleRad)};

    return pointInRectangle - closestPoint;
}

bool Ball::checkCollision(const RectangleShape &rectangleShape) const {
    Vec2 closestVec2 = getClosestPoint(rectangleShape);

    return hasReached(closestVec2);
}

void Ball::collide(const Bounceable &bounceable) {
    Log::get().addMessage(Log::LogType::DirVec, getDirvec());

    Log::get().addMessage(Log::LogType::CollidingObject,
                          std::string{"topLeft: "}
                              + std::string{bounceable.getTopLeft()});
    Log::get().addMessage(Log::LogType::CollidingObject,
                          std::string{"bottomRight: "}
                              + std::string{bounceable.getBottomRight()});

    Vec2 simplePenetrationvec = getSimplePenetrationVec(bounceable);
    Log::get().addMessage(Log::LogType::SimplePenetrationVec,
                          std::string{simplePenetrationvec});

    Vec2 closestPoint = getClosestPoint(bounceable);
    Log::get().addMessage(Log::LogType::ClosestPoint,
                          std::string{closestPoint});

    Bounceable::BounceType bounceType = bounceable.getBounceType(closestPoint);
    Log::get().addMessage(Log::LogType::BounceType,
                          Bounceable::bounceTypeToString(bounceType));

    Vec2 changeBetweenLastUpdate{center_ - prevCenter_};
    Log::get().addMessage(Log::LogType::ChangeBetweenLastUpdate,
                          changeBetweenLastUpdate);

    double penetrationRate = 1; // Default to 1 to prevent 0-division
    if (((bounceType == Bounceable::BounceType::Horizontal)
         || (bounceType == Bounceable::BounceType::Corner))
        && (changeBetweenLastUpdate.y != 0)) {
        penetrationRate = simplePenetrationvec.y / changeBetweenLastUpdate.y;

    } else if ((bounceType == Bounceable::BounceType::Vertical)
               && (changeBetweenLastUpdate.x != 0)) {
        penetrationRate = simplePenetrationvec.x / changeBetweenLastUpdate.x;
    }
    Log::get().addMessage(Log::LogType::PenetrationRate,
                          std::to_string(penetrationRate));

    Vec2 bidirectionalPenetrationVec =
        changeBetweenLastUpdate * penetrationRate;
    Log::get().addMessage(Log::LogType::BidirectionalPenetrationVec,
                          bidirectionalPenetrationVec);

    center_ -= bidirectionalPenetrationVec;

    bounce(bounceable);
    Log::get().addMessage(Log::LogType::DirVec,
                          std::string{"dirvec afterBounce: "}
                              + std::string{getDirvec()});

    // Add back the distance that the ball should have traveled instead of
    // going inside the Bounceable
    center_ += dirVec_ * bidirectionalPenetrationVec.getModule();
}

void Ball::update(double deltaTime) {
    if (isStuck()) {
        return;
    }

    prevCenter_ = center_;
    center_ += (dirVec_ * speed_ * deltaTime);
}
