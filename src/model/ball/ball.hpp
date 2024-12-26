#ifndef BALL_HPP
#define BALL_HPP

#include "../../global_variables.hpp"
#include "../bounceable/bounceable.hpp"
#include "../bounding_box/bounding_box.hpp"
#include "../vec2/vec2.hpp"

#include <math.h>

class Ball final {
  private:
    Vec2 pos_;
    Vec2 prevPos_;     // coordinate at the previous update
    Vec2 dirVec_;      // direction vector (always normalized)
    double radius_{1}; // TODO: do we need those 2 "{1}" ?
    double speed_{1};

    // #### Internal Helpers ####

    bool hasReached(const Vec2 &point) const;

    void bounce(const Bounceable &bounceable);

    Vec2 getClosestPoint(const BoundingBox &boundingBox) const;

  public:
    // #### Constructor ####

    Ball(Vec2 pos, Vec2 directionVec, double radius = BALL_RADIUS,
         double speed = BALL_SPEED);

    Ball(const Ball &other) = default;

    // #### Destructor ####

    ~Ball();

    // #### Getters ####

    double getRadius() const noexcept;

    const Vec2 &getPos() const noexcept;

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
