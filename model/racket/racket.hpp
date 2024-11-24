#ifndef RACKET_HPP
#define RACKET_HPP

#include "../bounceable/bounceable.hpp"
#include "../vec2/vec2.hpp"

class Racket : public Bounceable {
  private:
    virtual double getWidth() const;

    virtual const Vec2 &getCoordinate() const;

    virtual void setCoordinate(const Vec2 &coordinate);

  public:
    Racket(const BoundingBox &boundingBox);

    virtual Vec2 getDirVecAfterBounce(const Vec2 &closestPoint,
                                      const Vec2 &dirVec) const override;
};

#endif
