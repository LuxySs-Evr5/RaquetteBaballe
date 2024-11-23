#ifndef GAME_BOARD_HPP
#define GAME_BOARD_HPP

#include "../ball/ball.hpp"
#include "../brick/brick.hpp"

#include <memory>
#include <vector>

class GameBoard {
  private:
    std::vector<std::shared_ptr<Ball>> balls;
    std::vector<std::shared_ptr<Brick>> bricks;
    // Racket racket;

  public:
    void update(double deltaTime);
};

#endif
