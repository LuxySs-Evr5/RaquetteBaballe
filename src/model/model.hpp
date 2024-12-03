#ifndef MODEL_HPP
#define MODEL_HPP

#include "game_board/game_board.hpp"

class Model {
  private:
    GameBoard gameBoard;

  public:
    Model() = default;
    virtual ~Model() = default;

    virtual void update(double deltaTime);
};

#endif
