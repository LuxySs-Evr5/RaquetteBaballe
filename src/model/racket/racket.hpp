#ifndef RACKET_HPP
#define RACKET_HPP

#include "../bounceable/bounceable.hpp"
#include "../vec2/vec2.hpp"

class Racket final : public Bounceable {
  private:
    Vec2 previousPosition_;

  public:
    // #### Constructors ####

    Racket(const Racket &other) = default;

    Racket(const BoundingBox &boundingBox);

    Racket(const Vec2 &center, double width, double height);

    // #### Getters ####

    double getWidth() const;

    double getHeight() const;

    Vec2 getCoordinate() const;

    Vec2 getVelocity() const override;

    // ##### Setters ####

    void setCoordinate(const Vec2 &coordinate);

    void setWidth(double newWidth);

    void setHeight(double newHeight);

    void setPosX(double posX);

    // #### Bounceable Override ####

    Vec2 getDirVecAfterBounce(const Vec2 &closestPoint,
                              const Vec2 &dirVec = {0, 0}) const override;
};

#endif
