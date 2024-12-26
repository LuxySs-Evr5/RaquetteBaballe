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
    Vec2 prevPos_; // coordinate at the previous update
    Vec2 dirVec_;  // direction vector (always normalized)
    double radius_;
    double speed_;

    // #### Internal Helpers ####

    /**
     * @brief returns true if the ball has reached the given point, meaning the
     * point is inside the ball.
     */
    bool hasReached(const Vec2 &point) const;

    /**
     * @brief Changes the direction vector according to the given bounceable
     * effect on the ball.
     */
    void bounce(const Bounceable &bounceable);

    /**
     * @brief Returns the closest point from the ball laying on the
     * boundingBox's perimeter.
     */
    Vec2 getClosestPoint(const BoundingBox &boundingBox) const;

  public:
    // #### Constructors Operators ####

    /**
     * @brief Constructs a new Ball.
     *
     * @param pos The position.
     * @param directionVec The direction vector.
     * @param radius The radius.
     * @param speed The speed.
     */
    Ball(Vec2 pos, Vec2 directionVec, double radius = BALL_RADIUS,
         double speed = BALL_SPEED);

    Ball(const Ball &other) = default;

    Ball(Ball &&) = default;

    // #### Assignment Operators ####

    Ball &operator=(const Ball &) = default;

    Ball &operator=(Ball &&) = default;

    // #### Destructor ####

    virtual ~Ball() = default;

    // #### Getters ####

    /**
     * @brief Returns the ball's radius.
     */
    double getRadius() const noexcept;

    /**
     * @brief Returns the ball's position.
     */
    const Vec2 &getPos() const noexcept;

    /**
     * @brief Returns the ball's direction vector.
     */
    const Vec2 &getDirvec() const noexcept;

    // #### Setters ####

    /**
     * @brief Sets the ball's speed.
     * @param speed The speed.
     */
    void setSpeed(unsigned speed);

    /**
     * @brief Returns the ball's speed.
     * @param vec The direction vector.
     */
    void setDirVec(const Vec2 &vec);

    // #### Collision ####

    /**
     * @brief Returns the unidirectional-penetration-vector corresponding to the
     * given boundingBox.
     * @param boundingBox The BoundingBox.
     */
    Vec2 getUnidirectionalPenetration(const BoundingBox &boundingBox) const;

    /**
     * @brief Checks whether the ball has collided with the given BoundingBox.
     * @param boundingBox The BoundingBox.
     */
    bool checkCollision(const BoundingBox &boundingBox) const;

    /**
     * @brief Solves the collision between the ball and the given bounceable.
     * @param boundingBox The bounceable.
     */
    void collide(const Bounceable &bounceable);

    // #### Update ####

    /**
     * @brief Updates the ball's position as if it had travelled for a deltaTime
     * duration (seconds).
     * @param deltaTime The duration (seconds).
     */
    void update(double deltaTime);
};

#endif
