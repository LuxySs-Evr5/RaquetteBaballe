#ifndef RACKET_HPP
#define RACKET_HPP

#include "../bounceable/bounceable.hpp"
#include "../vec2/vec2.hpp"

class Racket : public Bounceable {
  private:
    virtual double getWidth() const;

    virtual Vec2 getCoordinate() const;

    virtual void setCoordinate(const Vec2 &coordinate);

  public:
    Racket(const BoundingBox &boundingBox);
    Racket(const Vec2 &center, double width, double height);

    // only need to know where the ball hit the racket
    // (dirVec is not necessary for the ball's bounce against the racket since
    // it doesn't use the previous dirVec)
    virtual Vec2 getDirVecAfterBounce(const Vec2 &closestPoint,
                                      const Vec2 &dirVec = {0,
                                                            0}) const override;

    virtual void setHorizontal(double x);
};

#endif
