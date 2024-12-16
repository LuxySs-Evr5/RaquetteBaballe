#include "game_board.hpp"
#include "../../log/log.hpp"

#include <algorithm>
#include <memory>
#include <optional>
#include <variant>

std::optional<std::variant<BrickIt, BorderIt, RacketIt>>
GameBoard::findNextCollision(Ball &ball) {
    std::optional<std::variant<BrickIt, BorderIt, RacketIt>> closestCollision;
    double distanceClosestCollision = std::numeric_limits<double>::max();

    // Helper lambda function
    auto checkCollisions = [&](auto &elements, auto &closestCollision) {
        for (auto it = elements.begin(); it != elements.end(); ++it) {
            if (ball.checkCollision((*it)->getBoundingBox())) {
                double distanceCurrentCollision =
                    ball.getUnidirectionalPenetration((*it)->getBoundingBox())
                        .getModule();

                if (distanceCurrentCollision < distanceClosestCollision) {
                    closestCollision = it;
                    distanceClosestCollision = distanceCurrentCollision;
                }
            }
        }
    };

    checkCollisions(bricks_, closestCollision);
    checkCollisions(borders_, closestCollision);
    checkCollisions(rackets_, closestCollision);

    return closestCollision;
}

void GameBoard::update(double deltaTime) {
    if (deltaTime == 0) { // We don't update because there is no update to do
        return;
    }

    for (auto ball : balls_) {

        Log::get().addMessage(Log::LogType::BallPos, ball->getCoordinate());

        bool collided = true;
        do {
            auto collidingObject = (findNextCollision(*ball));

            collided = collidingObject.has_value();
            if (!collided) {
                break;
            }

            if (std::holds_alternative<RacketIt>(collidingObject.value())) {
                Log::get().addMessage(Log::LogType::CollidingObject, "racket");
                RacketIt racketIt = std::get<RacketIt>(*collidingObject);
                ball->collide(*racketIt->get());
            } else if (std::holds_alternative<BrickIt>(
                           collidingObject.value())) {
                Log::get().addMessage(Log::LogType::CollidingObject, "brick");
                BrickIt brickIt = std::get<BrickIt>(*collidingObject);
                ball->collide(*brickIt->get());
                (*brickIt)->hit();               // decrement its durability
                if ((*brickIt)->isDestroyed()) { // erase it if destroyed
                    Log::get().addMessage(
                        Log::LogType::BrickDestroyed,
                        std::string{"Brick at "}
                            + string{(*brickIt)->getBoundingBox().getCenter()});
                    scoreManager_.increaseScore((*brickIt)->getScore());
                    bricks_.erase(brickIt);
                }
            } else if (std::holds_alternative<BorderIt>(
                           collidingObject.value())) {
                Log::get().addMessage(Log::LogType::CollidingObject, "border");
                BorderIt borderIt = std::get<BorderIt>(*collidingObject);
                ball->collide(*borderIt->get());
            }
        } while (collided);

        if (ball->getCoordinate().y < ball->getRadius() / 2) {
            balls_.erase(std::find(balls_.begin(), balls_.end(), ball));
            --lifeCounter_;
            if (lifeCounter_ > 0) { // TODO : check si on fait ca ici ? y a un
                                    // check de vie dans le controller
                balls_.emplace_back(
                    std::make_shared<Ball>(Vec2{450, 85}, Vec2{0, 1}, 10, 500));
            }
        }
        ball->update(deltaTime);
    }
}

void GameBoard::saveRecordScore() { scoreManager_.saveScore(); }

int GameBoard::getScore() const { return scoreManager_.getCurrentScore(); }

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

long unsigned int GameBoard::getNumBricks() const { return bricks_.size(); }

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


const int GameBoard::getBestScore() const {     // TODO: check because the same function in constructor of score_manager
    return bestScore_;
}


void GameBoard::resetBestScore() {
    bestScore_ = 0;
    scoreManager_.setScore0();
}


void GameBoard::pauseGameBoard() {

    
}