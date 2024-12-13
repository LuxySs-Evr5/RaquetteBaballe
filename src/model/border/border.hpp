#ifndef BORDER_HPP
#define BORDER_HPP

#include "../bounceable/bounceable.hpp"
#include "../bounding_box/bounding_box.hpp"

class Border final : public Bounceable {
  public:
    Border(const BoundingBox &boundingBox);
    virtual ~Border();
};

#endif
