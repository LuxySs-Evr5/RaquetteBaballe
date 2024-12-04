#ifndef MODEL_HPP
#define MODEL_HPP

#include "ball/ball.hpp"
#include "brick/brick.hpp"
#include "game_board/game_board.hpp"
#include "life/life.hpp"
#include "score/score.hpp"
#include <memory>
#include <vector>

class Model {
  private:
    GameBoard gameBoard_;
    Life life_;
    Score score_;

  public:
    Model(vector<shared_ptr<Brick>> bricks, vector<shared_ptr<Ball>> balls, Racket racket);
    virtual ~Model() = default;

    virtual void update(double deltaTime);

    int getNumberOfLifes() const;

    void moveRacketHorizontal(const double x);
    void saveScore();

    GameBoard getGameBoard() const;
    Score getScoreObject() const;
    Life getLifeObject() const;
};

#endif
