#ifndef BOUNCEABLE_HPP
#define BOUNCEABLE_HPP

#include "../bounding_box/bounding_box.hpp"
#include "../vec2/vec2.hpp"

enum class BounceType { Vertical, Horizontal, Corner };

/**
 * @brief Converts the given bounceType into the according string.
 * @note This is essentially for logging purpose.
 */
std::string bounceTypeToString(BounceType bounceType);

class Bounceable {
  protected:
    BoundingBox boundingBox_;

  protected:
    // #### Constructors ####

    /**
     * @brief Constructs a new Bounceable.
     * @param boundingBox the BoundingBox.
     */
    Bounceable(const BoundingBox &boundingBox);
    Bounceable(Vec2 pos, double width, double height);
    Bounceable(Vec2 topLeft, Vec2 bottomRight);
    Bounceable(const Bounceable &other) = default;

  public:
    // #### Destructor ####

    virtual ~Bounceable();

    // #### Getters ####

    /**
     * @brief Returns the Bounceable's BoundingBox.
     */
    const BoundingBox &getBoundingBox() const;

    // #### Bouncing ####

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
};

#endif
