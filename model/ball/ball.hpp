#ifndef BALL_HPP
#define BALL_HPP

#include "../point/point.hpp"
#include <math.h>

// NOTE: might wanna get inspo from translation class in labs to do the
// increased-speed nerf

enum class BounceType { horizontal, vertical };

class Ball {
  private:
    Point coord_;
    Point direction_;
    double radius_;
    double speed_;

  public:
    Ball(Point coord, Point direction, double radius = 1, double speed = 1);

    virtual ~Ball() = default;

    virtual Point getCoordinate();
    virtual void setSpeed(unsigned speed);
    virtual void setDirection(Point newDirection);

    virtual bool hasReached(Point point);

    virtual void update(double deltaTime);
    virtual void bounce(BounceType bounceType);
};

#endif
