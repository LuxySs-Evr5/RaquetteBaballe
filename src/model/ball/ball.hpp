#ifndef BALL_HPP
#define BALL_HPP

#include "../../global_variables.hpp"
#include "../bounceable/bounceable.hpp"
#include "../rectangle_shape/rectangle_shape.hpp"
#include "../vec2/vec2.hpp"

#include <math.h>

class Ball final {
  private:
    Vec2 center_;
    Vec2 prevCenter_; // coordinate at the previous update
    Vec2 dirVec_;     // direction vector (always normalized)
    double radius_;
    double speed_;

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
     * RectangleShape's perimeter.
     */
    Vec2 getClosestPoint(const RectangleShape &rectangle) const;

  public:
    /**
     * @brief Constructs a new Ball.
     *
     * @param center The position.
     * @param directionVec The direction vector.
     * @param radius The radius.
     * @param speed The speed.
     */
    Ball(const Vec2 &center, Vec2 directionVec, double radius = BALL_RADIUS,
         double speed = BALL_SPEED);

    Ball(const Ball &other) = default;

    Ball(Ball &&) = default;

    Ball &operator=(const Ball &) = default;

    Ball &operator=(Ball &&) = default;

    virtual ~Ball() = default;

    /**
     * @brief Returns the ball's radius.
     */
    double getRadius() const noexcept;

    /**
     * @brief Returns the ball's position.
     */
    const Vec2 &getCenter() const noexcept;

    /**
     * @brief Returns the ball's direction vector.
     */
    const Vec2 &getDirvec() const noexcept;

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

    /**
     * @brief Returns the simple-penetration-vector corresponding to the
     * given rectangleShape.
     * @param rectangleShape The RectangleShape.
     */
    Vec2 getSimplePenetrationVec(const RectangleShape &rectangleShape) const;

    /**
     * @brief Checks whether the ball has collided with the given
     * RectangleShape.
     * @param rectangleShape The RectangleShape.
     */
    bool checkCollision(const RectangleShape &rectangleShape) const;

    /**
     * @brief Solves the collision between the ball and the given bounceable.
     * @param bounceable The bounceable.
     */
    void collide(const Bounceable &bounceable);

    /**
     * @brief Updates the ball's position as if it had travelled for a deltaTime
     * duration (seconds).
     * @param deltaTime The duration (seconds).
     */
    void update(double deltaTime);
};

#endif
