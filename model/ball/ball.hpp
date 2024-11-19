#ifndef BALL_HPP
#define BALL_HPP

#include "../bricks/brick.hpp"
#include "../point/point.hpp"
#include "../vec2/vec2.hpp"

#include <math.h>

constexpr double DEFAULT_BALL_RADIUS = 1;
constexpr double DEFAULT_BALL_SPEED = 1;

// NOTE: might wanna get inspo from translation class in labs to do the
// increased-speed nerf

enum class BounceType { horizontal, vertical };

class Ball {
  private:
    Point coord_;
    Vec2 dirVec_; // direction vector (always normalized)
    double radius_{1};
    double speed_{1};

  public:
    Ball(Point coord, Vec2 directionVec, double radius = DEFAULT_BALL_RADIUS,
         double speed = DEFAULT_BALL_SPEED);

    virtual ~Ball() = default;

    virtual Point getCoordinate();
    virtual void setSpeed(unsigned speed);
    virtual void setDirectionX(int x);
    virtual void setDirectionY(int y);

    // this obviously works
    virtual bool hasReached(const Point &point) const;
    virtual Point getClosestPoint(const Rectangle &rectangle) const;
    virtual bool checkCollision(const Rectangle &rectangle) const;

    virtual void update(double deltaTime);
    virtual void bounce(BounceType bounceType);
};

#endif
