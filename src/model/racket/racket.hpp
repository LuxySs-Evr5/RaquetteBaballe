#ifndef RACKET_HPP
#define RACKET_HPP

#include "../bounceable/bounceable.hpp"
#include "../vec2/vec2.hpp"

class Racket final : public Bounceable {
  private:
    Vec2 previousPosition_;

  public:
    /**
     * @brief Constructs a new Racket.
     *
     * @param pos The racket's position.
     * @param width The racket's width.
     * @param height The racket's height.
     */
    Racket(const Vec2 &pos, double width, double height);

    /**
     * @brief Constructs a new Racket.
     *
     * @param boundingBox The racket's BoundingBox.
     */
    Racket(const BoundingBox &boundingBox);

    Racket(const Racket &other) = default;
    Racket(Racket &&) = default;
    Racket &operator=(const Racket &) = default;
    Racket &operator=(Racket &&) = default;

    virtual ~Racket() = default;

    /**
     * @brief Returns the racket's width.
     */
    double getWidth() const;

    /**
     * @brief Returns the racket's height.
     */
    double getHeight() const;

    /**
     * @brief Returns the racket's position.
     */
    Vec2 getPos() const;

    /**
     * @brief Sets the racket's width.
     *
     * @param newWidth The new width.
     */
    void setWidth(double newWidth);

    /**
     * @brief Sets the racket's height.
     *
     * @param newHeight The new height.
     */
    void setHeight(double newHeight);

    /**
     * @brief Sets the racket's position.
     *
     * @param newHeight The new position.
     */
    void setPosX(double posX);

    /**
     * @brief Calculates the ball's new direction vector after bouncing off the
     * Racket.
     *
     * @param closestPoint The closest point of contact on the rectangle.
     * @param currentDirection The current direction vector of the ball.
     */
    Vec2 getDirVecAfterBounce(const Vec2 &closestPoint,
                              const Vec2 &dirVec) const override;
};

#endif
