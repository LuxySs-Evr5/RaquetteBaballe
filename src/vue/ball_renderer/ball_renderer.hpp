#ifndef BALL_RENDERER_HPP
#define BALL_RENDERER_HPP

#include "../../model/ball/ball.hpp"

class BallRenderer {
  public:
    void render(const Ball &ball) const;
};

#endif
