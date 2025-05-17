#ifndef BOUNCEABLE_HPP
#define BOUNCEABLE_HPP

#include "../rectangle_shape/rectangle_shape.hpp"
#include "../vec2/vec2.hpp"

class Bounceable : public RectangleShape {
  public:
    enum class BounceType { Vertical, Horizontal, Corner };

  protected:
    /**
     * @brief Constructs a new Bounceable.
     *
     * @param center The center coordinate.
     * @param width The width.
     * @param height The height.
     */
    Bounceable(const Vec2 &center, double width, double height);

    /**
     * @brief Constructs a new Bounceable.
     *
     * @param topLeft The top-left corner coordinate.
     * @param bottomRight The bottom-right corner coordinate.
     */
    Bounceable(const Vec2 &topLeft, const Vec2 &bottomRight);
    Bounceable(const Bounceable &other) = default;
    Bounceable(Bounceable &&) = default;
    Bounceable &operator=(const Bounceable &) = default;
    Bounceable &operator=(Bounceable &&) = default;

  public:
    virtual ~Bounceable();

    /**
     * @brief Calculates the ball's new direction vector after bouncing off the
     * Bounceable. This default implementation should be overridden by the
     * racket to handle angle-specific behavior.
     *
     * @param closestPoint The closest point of contact on the rectangle.
     * @param currentDirection The current direction vector of the ball.
     */
    virtual Vec2 getDirVecAfterBounce(const Vec2 &closestPoint,
                                      const Vec2 &dirVec) const;

    /**
     * @brief Returns the bounce type (corner, horizontal, or vertical)
     * based on the ball's contact point.
     *
     * @param point The closest point of contact on the rectangle.
     */
    virtual BounceType getBounceType(const Vec2 &point) const final;

    /**
     * @brief Converts the given bounceType into the according string.
     * @note This is essentially for logging purpose.
     */
    static std::string bounceTypeToString(BounceType bounceType);
};

#endif
