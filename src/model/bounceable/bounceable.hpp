#ifndef BOUNCEABLE_HPP
#define BOUNCEABLE_HPP

#include "../bounding_box/bounding_box.hpp"
#include "../vec2/vec2.hpp"

class Bounceable {
  protected:
    BoundingBox boundingBox_;

  public:
    Bounceable(const BoundingBox &boundingBox);
    Bounceable(Vec2 center, double width, double height);
    Bounceable(Vec2 topLeft, Vec2 bottomRight);
    virtual ~Bounceable();

    const BoundingBox &getBoundingBox() const;

    // default one, the racket will have to reimplement its own version (bc of
    // the angle).
    //
    // Pass it the closest point from the ball that is on the
    // rectangle as well as the current direction vector and it gives you the
    // new direction vector after the bounce on *this
    virtual Vec2 getDirVecAfterBounce(const Vec2 &closestPoint,
                                      const Vec2 &dirVec) const;

    virtual BounceType getBounceType(const Vec2 &point) const;
};

#endif
