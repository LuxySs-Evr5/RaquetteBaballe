#ifndef MODEL_HPP
#define MODEL_HPP

#include "game_board/game_board.hpp"
#include "life/life.hpp"
#include "score/score.hpp"

class Model {
  private:
    GameBoard gameBoard_;
    Life life_;
    Score score_;

  public:
    Model() = default;
    virtual ~Model() = default;

    virtual void update(double deltaTime);

    int getNumberOfLifes() const;

    void saveScore();
};

#endif
