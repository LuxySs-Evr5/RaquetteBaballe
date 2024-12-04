#include "model.hpp"


Model::Model(std::vector<std::shared_ptr<Brick>> bricks,
             std::vector<std::shared_ptr<Ball>> balls, Racket racket)
    : gameBoard_(balls, bricks, racket) {
  life_ = Life(3);
    score_ = Score();
    }


void Model::update(double deltaTime) { gameBoard_.update(deltaTime); }


int Model::getNumberOfLifes() const { return life_.getNbLifes(); }

void Model::moveRacketHorizontal(const double x) { gameBoard_.moveRacketHorizontal(x); }

void Model::saveScore() { score_.save(); }

GameBoard Model::getGameBoard() const { return gameBoard_; }

Score Model::getScoreObject() const { return score_; }

Life Model::getLifeObject() const { return life_; }
