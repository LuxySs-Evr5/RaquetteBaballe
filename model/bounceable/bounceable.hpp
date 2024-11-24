#ifndef BOUNCEABLE_HPP
#define BOUNCEABLE_HPP

#include "../bounding_box/bounding_box.hpp"
#include "../vec2/vec2.hpp"

class Bounceable {
  private:
    BoundingBox boundingBox_;

  public:
    Bounceable(Vec2 center, double width, double height);
    Bounceable(Vec2 topLeft, Vec2 bottomRight);

    const BoundingBox &getBoundingBox() const;
};

#endif
