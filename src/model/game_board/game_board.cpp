#include "game_board.hpp"
#include "../../log/log.hpp"
#include "../collision_solver/collision_solver.hpp"

#include <algorithm>
#include <memory>
#include <sys/types.h>

void GameBoard::update(double deltaTime) {

    CollisionSolver collisionSolver{rackets_[0], borders_, bricks_};

    if (deltaTime == 0) { // We don't update because there is no update to do
        return;
    }

    for (auto ball : balls_) {

        Log::get().addMessage(Log::LogType::BallPos, ball->getCoordinate());

        // solve collisions here
        size_t scoreToAdd = collisionSolver.solveBallCollisions(*ball);
        scoreManager_.increaseScore(scoreToAdd);

        if (ball->getCoordinate().y < ball->getRadius() / 2) {
            balls_.erase(std::find(balls_.begin(), balls_.end(), ball));
            --lifeCounter_;
            if (lifeCounter_ > 0) { // TODO : check si on fait ca ici ? y a un
                                    // check de vie dans le controller
                balls_.emplace_back(std::make_shared<Ball>(
                    Vec2{BOARD_WIDTH / 2 + WALL_THICKNESS - 1, 85}, Vec2{0, 1},
                    BALL_RADIUS, BALL_SPEED));
            }
        }
        ball->update(deltaTime);
    }
}

void GameBoard::saveRecordScore() { scoreManager_.saveScore(); }

unsigned long GameBoard::getScore() const {
    return scoreManager_.getCurrentScore();
}

const LifeCounter &GameBoard::getLife() const { return lifeCounter_; }

void GameBoard::setRacketAtX(double posX) { rackets_.at(0)->setPosX(posX); }

// #### Getters meant to be used by the View ####

// TODO: make the balls pointers const
const std::vector<std::shared_ptr<Ball>> &GameBoard::getBalls() const {
    return balls_;
}

const std::vector<std::shared_ptr<Brick>> &GameBoard::getBricks() const {
    return bricks_;
}

const std::vector<std::shared_ptr<Racket>> &GameBoard::getRackets() const {
    return rackets_;
}

const std::vector<std::shared_ptr<Border>> &GameBoard::getBorders() const {
    return borders_;
}

unsigned long GameBoard::getNumBricks() const {
    // TODO: Voir avec Luacs si c'est bien de faire ca
    unsigned long numBricks = 0;
    for (auto &brick : bricks_) {
        if (brick->getColor() != Color::gold) ++numBricks;
    }
    return numBricks;
}

void GameBoard::resetLifeCounter() { lifeCounter_.reset(); } // reset the life

void GameBoard::resetScore() { scoreManager_.resetScore(); } // reset the score

// ### Setters ###
void GameBoard::setBalls(const std::vector<std::shared_ptr<Ball>> balls) {
    balls_ = balls;
}

void GameBoard::setBricks(const std::vector<std::shared_ptr<Brick>> bricks) {
    bricks_ = bricks;
}

void GameBoard::setRacket(const std::vector<std::shared_ptr<Racket>> rackets) {
    rackets_ = rackets;
}

void GameBoard::setBorders(const std::vector<std::shared_ptr<Border>> borders) {
    borders_ = borders;
}

// #### Clear GameBoard ####

void GameBoard::clearRackets() { rackets_.clear(); }

void GameBoard::clearBalls() { balls_.clear(); }

void GameBoard::clearBorders() { borders_.clear(); }

void GameBoard::clearBricks() { bricks_.clear(); }

void GameBoard::clear() {
    clearBalls();
    clearBorders();
    clearBricks();
    clearRackets();
}

// ### Get the best score from the file ###
void GameBoard::readBestScore() {
    // TODO: check because the same function in constructor of score_manager
    std::string filePath = "score.txt";

    std::ifstream read(filePath, ios::in);

    if (read.is_open()) {
        read >> bestScore_;
        read.close();
    }
}

int GameBoard::getBestScore() const { // TODO: check because the same function
                                      // in constructor of score_manager
    return bestScore_;
}

void GameBoard::resetBestScore() {
    bestScore_ = 0;
    scoreManager_.setScore0();
}

void GameBoard::pauseGameBoard() {}
