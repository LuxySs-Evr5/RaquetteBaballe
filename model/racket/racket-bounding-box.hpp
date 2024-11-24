#ifndef RACKET_BOUNDING_BOX_HPP
#define RACKET_BOUNDING_BOX_HPP

#include "../bounding_box/bounding_box.hpp"
#include "../vec2/vec2.hpp"

class RacketBoundingBox : public BoundingBox {
  private:
    virtual void bounce() override;

  public:
    RacketBoundingBox(Vec2 center, double width, double height);
    RacketBoundingBox(Vec2 topLeft, Vec2 bottomRight);
};

#endif
