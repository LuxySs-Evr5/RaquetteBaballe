#include "game_board.hpp"
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
    // std::cout << "racket at " << rackets_[0]->getBoundingBox().getCenter();
    // std::cout << " top left " << rackets_[0]->getBoundingBox().getTopLeft();
    // std::cout << " bottom right "
    //           << rackets_[0]->getBoundingBox().getBottomRight() << std::endl;

    for (auto ball : balls_) {
        std::cout << "coord: " << ball->getCoordinate() << std::endl;

        bool collided = true;
        do {
            auto collidingObject = (findNextCollision(*ball));

            collided = collidingObject.has_value();
            if (!collided) {
                std::cout << "No collision detected!" << std::endl;
                break;
            }

            // Check if collision with racket
            if (std::holds_alternative<RacketIt>(collidingObject.value())) {
                std::cout << "Collision with racket!" << std::endl;
                RacketIt racketIt = std::get<RacketIt>(*collidingObject);
                ball->collide(*racketIt->get());
            } // Check if collision with brick
            else if (std::holds_alternative<BrickIt>(collidingObject.value())) {
                std::cout << "Collision with a brick!" << std::endl;
                BrickIt brickIt = std::get<BrickIt>(*collidingObject);
                ball->collide(*brickIt->get());
                (*brickIt)->hit();               // decrement its durability
                if ((*brickIt)->isDestroyed()) { // erase it if destroyed
                    std::cout << "erasing brick " << std::endl;
                    bricks_.erase(brickIt);
                    addScore(); // add 1 to the score because a brick is destroyed
                }
            } // Check if collision with border
            else if (std::holds_alternative<BorderIt>(
                         collidingObject.value())) {
                std::cout << "Collision with a border!" << std::endl;
                BorderIt borderIt = std::get<BorderIt>(*collidingObject);
                ball->collide(*borderIt->get());
            }

            std::cout << "repositionned at " << ball->getCoordinate()
                      << std::endl;
        } while (collided);

        if (ball->getCoordinate().y < - 5) { // if the ball is out of the screen (-5 because the ball is 10px wide)
            balls_.erase(std::find(balls_.begin(), balls_.end(), ball));
            life_.removeOneLife();
            if (life_.getNbLifes() > 0) { // TODO : check si on fait ca ici ? y a un check de vie dans le controller
            balls_.push_back(std::make_shared<Ball>(Vec2{450, 85}, Vec2{0, 1}, 10, 500));
            }
        }

        ball->update(deltaTime);
        std::cout << std::endl;
    }
}

void GameBoard::saveCurrentScore() { score_.saveScore(); }

string GameBoard::getStringScore() { return score_.getScoreString(); }

int GameBoard::getIntScore() { return score_.getScore(); }

int GameBoard::getLife() { return life_.getNbLifes(); }

void GameBoard::setRacketAtX(double posX) { rackets_.at(0)->setPosX(posX); }

// #### getters meant to be used by the View ####

// TODO: make the balls pointers const
std::vector<std::shared_ptr<Ball>> &GameBoard::getBalls() { return balls_; }

std::vector<std::shared_ptr<Brick>> &GameBoard::getBricks() { return bricks_; }

std::shared_ptr<Racket> &GameBoard::getRacket() { return rackets_.at(0); }

const std::vector<std::shared_ptr<Border>> &GameBoard::getBorders() const {
    return borders_;
}

void GameBoard::addScore() { score_.addScore(1); } // add 1 to the score if a brick is destroyed