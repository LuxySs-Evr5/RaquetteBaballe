#include "ball.hpp"

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

bool Ball::isOnThePoint(const Point &point) const {
    int deltaX = point.x - coord_.x;
    int deltaY = point.y - coord_.y;

    return Vec2{deltaX, deltaY}.getModule() <= radius_;
}

// NOTE: This is where you stopped working last night,
// now you have to implement the way to detect on which side it bounced
// so that you can do the right bounce type
bool Ball::checkInBounceArea(const Rectangle &rectangle) {
    Point topLeft = rectangle.getTopLeft();
    Point bottomRight = rectangle.getBottomRight();

    // TODO: this is where size_t and double limitiations happen
    Point areatopLeft{topLeft.x + static_cast<size_t>(radius_),
                      static_cast<size_t>(topLeft.y + radius_)};

    Point areaBottomRight{bottomRight.x + static_cast<size_t>(radius_),
                          static_cast<size_t>(bottomRight.y + radius_)};

    return (areatopLeft.x <= coord_.x) and (coord_.x <= areaBottomRight.x)
           and (areaBottomRight.y <= coord_.y) and (coord_.x <= areatopLeft.y);
}
