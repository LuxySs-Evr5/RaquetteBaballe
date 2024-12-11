#ifndef BRICK_RENDERER_HPP
#define BRICK_RENDERER_HPP

#include "../../model/brick/brick.hpp"

class BrickRenderer {
  public:
    void render(const Brick &brick) const;
};

#endif
