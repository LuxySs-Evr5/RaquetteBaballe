#ifndef BALL_RENDERER_HPP
#define BALL_RENDERER_HPP

#include "../../model/ball/ball.hpp"

class BallRenderer {
  public:
    /**
     * @brief Transform the ball to a BallUi and draw it.
     * 
     * @param ball 
     */
    void render(const Ball &ball) const;
};

#endif
