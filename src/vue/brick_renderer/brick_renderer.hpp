#ifndef BRICK_RENDERER_HPP
#define BRICK_RENDERER_HPP

#include "../../model/brick/brick.hpp"

class BrickRenderer {
  public:
    /**
     * @brief Transform a brick into a brickUI and draw it.
     * 
     * @param brick 
     */
    void render(const Brick &brick) const;
};

#endif
