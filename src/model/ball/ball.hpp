#ifndef BALL_HPP
#define BALL_HPP

#include "../bounceable/bounceable.hpp"
#include "../bounding_box/bounding_box.hpp"
#include "../vec2/vec2.hpp"
#include "../../global_variables.hpp"

#include <math.h>

// NOTE: might wanna get inspo from translation class in labs to do the
// increased-speed nerf

class Ball {
  private:
    Vec2 coord_;
    Vec2 prevCoord_; // coordinate at the previous update
    Vec2 dirVec_;    // direction vector (always normalized)
    double radius_{1};
    double speed_{1};

    // #### Internal Helpers ####

    bool hasReached(const Vec2 &point) const;

    void bounce(const Bounceable &bounceable);

    Vec2 getClosestPoint(const BoundingBox &boundingBox) const;

  public:
    // #### Constructor ####

    Ball(Vec2 coord, Vec2 directionVec, double radius = BALL_RADIUS,
         double speed = BALL_SPEED);

    // #### Destructor ####

    ~Ball();

    // #### Getters ####

    double getRadius() const noexcept;

    const Vec2 &getCoordinate() const noexcept;

    const Vec2 &getDirvec() const noexcept;

    // #### Setters ####

    void setSpeed(unsigned speed);

    void setDirection(const Vec2 &vec);

    // #### Collision ####

    Vec2 getUnidirectionalPenetration(const BoundingBox &boundingBox) const;

    bool checkCollision(const BoundingBox &boundingBox) const;

    void collide(const Bounceable &bounceable);

    // #### Update ####

    void update(double deltaTime);
};

#endif
