#ifndef RACKET_HPP
#define RACKET_HPP

#include "../bounceable/bounceable.hpp"
#include "../vec2/vec2.hpp"

class Racket final : public Bounceable {
  private:
    Vec2 previousPosition_;

    // TODO: fix weird stuff with private getters

    virtual double getWidth() const;
    virtual double getHeight() const;

    virtual Vec2 getCoordinate() const;

    virtual void setCoordinate(const Vec2 &coordinate);

  public:
    // #### Constructors ####

    Racket(const BoundingBox &boundingBox);
    Racket(const Racket &other) = default;
    Racket(const Vec2 &center, double width, double height);

    // #### Getters ####

    virtual Vec2 getVelocity() const override;

    // ##### Setters ####

    virtual void setPosX(double posX);

    // #### Bounceable Override ####

    virtual Vec2 getDirVecAfterBounce(const Vec2 &closestPoint,
                                      const Vec2 &dirVec = {0,
                                                            0}) const override;
};

#endif
