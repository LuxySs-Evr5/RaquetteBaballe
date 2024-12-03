#include "model.hpp"

void Model::update(double deltaTime) { gameBoard_.update(deltaTime); }


int Model::getNumberOfLifes() const { return life_.getNbLifes(); }

void Model::saveScore() { score_.save(); }

Score Model::getScoreObject() const { return score_; }

Life Model::getLifeObject() const { return life_; }
