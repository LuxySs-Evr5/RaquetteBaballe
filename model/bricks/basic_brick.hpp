#ifndef BASIC_BRICK_HPP
#define BASIC_BRICK_HPP

#include "brick.hpp"

class BasicBrick : public Brick {
  public:
    BasicBrick(Color color, Point topLeft, Point bottomRight,
               uint8_t durability = 1);
};

#endif
