#ifndef BASIC_BRICK_HPP
#define BASIC_BRICK_HPP

#include "brick.hpp"

class BasicBrick : public Brick {
  public:
    BasicBrick(Color color, Rectangle rectangle, uint8_t durability);
};

#endif
