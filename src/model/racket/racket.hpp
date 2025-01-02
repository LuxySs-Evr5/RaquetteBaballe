#ifndef RACKET_HPP
#define RACKET_HPP

#include "../bounceable/bounceable.hpp"
#include "../vec2/vec2.hpp"

class Racket final : public Bounceable {
  public:
    /**
     * @brief Constructs a new Racket.
     *
     * @param center The racket's position.
     * @param width The racket's width.
     * @param height The racket's height.
     */
    Racket(const Vec2 &center, double width, double height);

    Racket(const Racket &other) = default;
    Racket(Racket &&) = default;
    Racket &operator=(const Racket &) = default;
    Racket &operator=(Racket &&) = default;

    virtual ~Racket() = default;

    /**
     * @brief Sets the racket's position.
     *
     * @param centerX The new x-axis position.
     */
    void setCenterX(double centerX);

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
