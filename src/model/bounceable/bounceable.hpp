#ifndef BOUNCEABLE_HPP
#define BOUNCEABLE_HPP

#include "../bounding_box/bounding_box.hpp"
#include "../vec2/vec2.hpp"

enum class BounceType { Vertical, Horizontal, Corner };

std::string bounceTypeToString(BounceType bounceType);

class Bounceable {
  protected:
    BoundingBox boundingBox_;

  public:
    // #### Constructors ####

    Bounceable(const BoundingBox &boundingBox);
    Bounceable(const Bounceable &other) = default;
    Bounceable(Vec2 pos, double width, double height);
    Bounceable(Vec2 topLeft, Vec2 bottomRight);

    // #### Destructor ####

    virtual ~Bounceable();

    // #### Getters ####

    const BoundingBox &getBoundingBox() const;

    // TODO: is this considered as a getter for non-brick Bounceables ?
    virtual Vec2 getVelocity() const;

    // #### Bouncing ####

    // default one, the racket will have to reimplement its own version (bc of
    // the angle).
    //
    // Pass it the closest point from the ball that is on the
    // rectangle as well as the current direction vector and it gives you the
    // new direction vector after the bounce on *this
    virtual Vec2 getDirVecAfterBounce(const Vec2 &closestPoint,
                                      const Vec2 &dirVec) const;

    virtual BounceType getBounceType(const Vec2 &point) const final;
};

#endif
