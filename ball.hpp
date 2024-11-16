#include "point.hpp"
#include <math.h>

// NOTE: might wanna get inspo from translation class in labs to do the
// increased-speed nerf

enum class BounceType { horizontal, vertical };

class Ball {
  private:
    Point coord_;
    Point direction_;
    unsigned speed_;

  public:
    Ball(Point coord, Point direction, unsigned speed = 1)
        : coord_{coord}, direction_{direction}, speed_{speed} {}

    virtual ~Ball() = default;

    virtual Point getCoordinate() { return coord_; }
    virtual void setSpeed(unsigned speed) { speed_ = speed; };
    virtual void setDirection(Point newDirection) { direction_ = newDirection; }

    virtual void update() {
        coord_.x += direction_.x * speed_;
        coord_.y += direction_.y * speed_;
    }

    void bounce(BounceType bounceType) {
        if (bounceType == BounceType::horizontal) {
            direction_.y = -direction_.y;
        } else if (bounceType == BounceType::vertical) {
            direction_.x = -direction_.x;
        }
    }
};
