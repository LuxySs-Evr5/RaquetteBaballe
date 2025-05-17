#include "game_board.hpp"
#include "../../log/log.hpp"
#include "../bonus/basic_timed_bonus.hpp"
#include "../bonus/slowdown_bonus.hpp"

#include <algorithm>
#include <cstddef>
#include <iterator>
#include <memory>
#include <vector>
#include <numbers>


template <typename T>
void GameBoard::removeSharedPointers(
    std::vector<std::shared_ptr<T>> &mainVector,
    const std::vector<std::shared_ptr<T>> &toRemove) {
    mainVector.erase(
        std::remove_if(mainVector.begin(), mainVector.end(),
                       [&toRemove](const std::shared_ptr<T> &element) {
                           return std::any_of(
                               toRemove.begin(), toRemove.end(),
                               [&element](const std::shared_ptr<T> &item) {
                                   return element == item;
                               });
                       }),
        mainVector.end());
}

std::optional<std::variant<BrickIt, BorderIt, std::shared_ptr<Racket>>>
GameBoard::findNextCollision(Ball &ball) {
    std::optional<std::variant<BrickIt, BorderIt, std::shared_ptr<Racket>>>
        closestCollision;
    double distanceClosestCollision = std::numeric_limits<double>::max();

    auto checkCollisions = [&](auto &elements, auto &closestCollision) {
        for (auto it = elements.begin(); it != elements.end(); ++it) {
            if (ball.checkCollision(**it)) {
                double distanceCurrentCollision =
                    ball.getSimplePenetrationVec((**it)).getModule();

                if (distanceCurrentCollision < distanceClosestCollision) {
                    closestCollision = it;
                    distanceClosestCollision = distanceCurrentCollision;
                }
            }
        }
    };

    checkCollisions(bricks_, closestCollision);
    checkCollisions(borders_, closestCollision);

    if (racket_ && ball.checkCollision(*racket_)) {
        double distanceCurrentCollision =
            ball.getSimplePenetrationVec(*racket_).getModule();

        if (distanceCurrentCollision < distanceClosestCollision) {
            closestCollision = racket_;
            distanceClosestCollision = distanceCurrentCollision;
        }
    }

    return closestCollision;
}

void GameBoard::handleBallBrickCollision(Ball &ball, BrickIt brickIt) {
    ball.collide(**brickIt);
    BonusType bonusType =
        (*brickIt)->hit(); // decrement its durability and extract bonus
    if ((*brickIt)->isDestroyed()) {
        Log::get().addMessage(Log::LogType::BrickDestroyed,
                              std::string{"Brick at "}
                                  + string{(*brickIt)->getCenter()});

        if (bonusType != BonusType::None && numBalls() == 1) {
            addDescendingBonus(
                {(*brickIt)->getCenter().x,
                 (*brickIt)->getBottom() - (BONUS_PILL_HEIGHT / 2)},
                bonusType);
        }

        scoreManager_.increaseScore((*brickIt)->getScore());
        bricks_.erase(brickIt);
    }
}

void GameBoard::handleDescendingBonuses(double deltaTime) {
    std::vector<shared_ptr<BonusPill>> bonusesToRemove;

    for (std::shared_ptr<BonusPill> &descendingBonus : descendingBonuses_) {
        descendingBonus->update(deltaTime);
        if (descendingBonus->getCenter().y < 0) {
            bonusesToRemove.push_back(descendingBonus);
        } else if (descendingBonus->isOverlapping(*racket_)) {
            bonusesToRemove.push_back(descendingBonus);
            BonusType bonusType = descendingBonus->getBonusType();
            applyBonus(bonusType);
        }
    }

    removeSharedPointers(descendingBonuses_, bonusesToRemove);
}

void GameBoard::handleActiveBonus(double deltaTime) {
    if (activeBonus_ != nullptr) {
        bool isActive = activeBonus_->update(deltaTime);
        BonusType bonusType = activeBonus_->getBonusType();
        if (bonusType == BonusType::SlowDown) {
            SlowDownBonus *slowDownBonus =
                dynamic_cast<SlowDownBonus *>(activeBonus_.get());
            if (slowDownBonus) {
                double slowDownFactor = slowDownBonus->getSlowDownFactor();
                balls_.at(0)->setSpeed(BALL_SPEED / slowDownFactor);
            } else {
                Log::get().addMessage(
                    Log::LogType::Error,
                    "activeBonus_ was expected to be of type SlowDownBonus "
                    "based on its BonusType, but it is not.");
            }
        } else if (bonusType == BonusType::StickyRacket) {
            if (balls_.at(0)->isStuck()) {
                balls_.at(0)->setCenter(
                    {racket_->getCenter().x,
                     racket_->getTop() + balls_.at(0)->getRadius()});
                balls_.at(0)->setDirVec(BALL_INITIAL_DIRECTION);
            }
        }

        if (!isActive) {
            undoBonusEffect(bonusType);
            activeBonus_.reset();
        }
    }
}

void GameBoard::handleLazers(double deltaTime) {
    vector<shared_ptr<Lazer>> lazersToRemove;
    vector<shared_ptr<AbstractBrick>> bricksToRemove;

    for (shared_ptr<Lazer> &lazer : lazers_) {
        lazer->update(deltaTime);
        if (lazer->getTop() > BOARD_HEIGHT - WALL_THICKNESS) {
            lazersToRemove.push_back(lazer);
        }
        for (shared_ptr<AbstractBrick> &brick : bricks_) {
            if (lazer->isOverlapping(*brick)) {
                if (brick->getColor() != AbstractBrick::Color::gold) {
                    bricksToRemove.push_back(brick);
                    scoreManager_.increaseScore(brick->getScore());
                }
                lazersToRemove.push_back(lazer);
                break;
            }
        }
    }

    removeSharedPointers(lazers_, lazersToRemove);
    removeSharedPointers(bricks_, bricksToRemove);
}

void GameBoard::handleBalls(double deltaTime) {
    vector<shared_ptr<Ball>> ballsToRemove;
    for (shared_ptr<Ball> &ball : balls_) {
        ball->update(deltaTime);

        Log::get().addMessage(Log::LogType::BallPos, ball->getCenter());

        solveBallCollisions(*ball);

        if (ball->getCenter().y < -ball->getRadius()) {
            ballsToRemove.push_back(ball);
        }
    }

    removeSharedPointers(balls_, ballsToRemove);
}

void GameBoard::updateLifeCounter() {
    if (balls_.empty()) {
        --lifeCounter_;
        if (lifeCounter_ > 0) {
            balls_.emplace_back(createBall());
        }
    }
}

void GameBoard::solveBallCollisions(Ball &ball) {
    bool collided = true;
    std::optional<std::variant<BrickIt, BorderIt, shared_ptr<Racket>>>
        collidingObject, prevCollidingObject;
    size_t consecutiveCollisions = 0;

    do {
        collidingObject = (findNextCollision(ball));

        collided = collidingObject.has_value();
        if (!collided) {
            break;
        }

        // apply the sticky racket if necessary
        if (activeBonus_ != nullptr
            && activeBonus_->getBonusType() == BonusType::StickyRacket) {
            for (shared_ptr<Ball> &ball : balls_) {
                if (ball->checkCollision(*racket_)) {
                    ball->setIsStuck(true);
                }
            }
        }

        if (prevCollidingObject.has_value()
            && collidingObject == prevCollidingObject) {
            consecutiveCollisions++;
        } else {
            consecutiveCollisions = 1;
        }

        // Prevent the ball from getting stuck inside of the collided
        // object.
        if (consecutiveCollisions > MAX_CONSECUTIVE_COLLISION) {
            break;
        }

        if (std::holds_alternative<shared_ptr<Racket>>(
                collidingObject.value())) {
            shared_ptr<Racket> racket =
                std::get<shared_ptr<Racket>>(*collidingObject);
            Log::get().addMessage(Log::LogType::CollidingObject, "racket");
            ball.collide(*racket_);
        } else if (std::holds_alternative<BrickIt>(collidingObject.value())) {
            Log::get().addMessage(Log::LogType::CollidingObject, "brick");
            BrickIt brickIt = std::get<BrickIt>(*collidingObject);
            handleBallBrickCollision(ball, brickIt);
        } else if (std::holds_alternative<BorderIt>(collidingObject.value())) {
            Log::get().addMessage(Log::LogType::CollidingObject, "border");
            BorderIt borderIt = std::get<BorderIt>(*collidingObject);
            ball.collide(**borderIt);
        }

        prevCollidingObject = collidingObject;

    } while (collided);
}

size_t GameBoard::numBalls() { return balls_.size(); }

void GameBoard::applyBonus(BonusType bonusType) {
    if (numBalls() > 1) {
        return;
    }

    if (activeBonus_ != nullptr && activeBonus_->getBonusType() != bonusType) {
        undoBonusEffect(activeBonus_->getBonusType());
    }

    switch (bonusType) {
    case BonusType::SlowDown: {
        if (activeBonus_ != nullptr
            && activeBonus_->getBonusType() == BonusType::SlowDown) {
            activeBonus_->reapply();
        } else {
            activeBonus_ = make_unique<SlowDownBonus>();
        }
        break;
    }
    case BonusType::WideRacket:
        activeBonus_ = make_unique<BasicTimedBonus>(BonusType::WideRacket);
        racket_->setWidth(WIDE_RACKET_WIDTH);
        break;
    case BonusType::StickyRacket:
        activeBonus_ = make_unique<BasicTimedBonus>(BonusType::StickyRacket);
        break;
    case BonusType::Lazer:
        activeBonus_ = make_unique<BasicTimedBonus>(BonusType::Lazer);
        break;
    case BonusType::SplitBall: {
        vector<shared_ptr<Ball>> newBalls;
        for (const std::shared_ptr<Ball> &ball : balls_) {
            splitBallIntoThree(*ball, newBalls);
        }
        std::move(newBalls.begin(), newBalls.end(), std::back_inserter(balls_));
        break;
    }
    case BonusType::ExtraLife:
        ++lifeCounter_;
        break;
    case BonusType::None:
        break;
    default:
        break;
    }
}

void GameBoard::undoBonusEffect(BonusType bonusType) {
    switch (bonusType) {
    case BonusType::SlowDown:
        balls_.at(0)->setSpeed(BALL_SPEED);
        break;
    case BonusType::WideRacket:
        racket_->setWidth(RACKET_WIDTH);
        break;
    case BonusType::StickyRacket:
        balls_.at(0)->setIsStuck(false);
        break;
    case BonusType::Lazer:
        break;
    case BonusType::SplitBall:
        break;
    case BonusType::ExtraLife:
        break;
    case BonusType::None:
        break;
    default:
        break;
    }

    activeBonus_.reset();
}

void GameBoard::addDescendingBonus(const Vec2 &center, BonusType bonusType) {
    descendingBonuses_.emplace_back(make_shared<BonusPill>(center, bonusType));
}

shared_ptr<Ball> GameBoard::createBall() {
    double ballSpawnYPos = RACKET_Y_POSITION + BALL_RADIUS + RACKET_WIDTH;

    return std::make_shared<Ball>(
        Vec2{BOARD_WIDTH / 2 + WALL_THICKNESS, ballSpawnYPos},
        BALL_INITIAL_DIRECTION, BALL_RADIUS, BALL_SPEED);
}

void GameBoard::splitBallIntoThree(const Ball &originalBall,
                                   std::vector<shared_ptr<Ball>> &newBalls) {
    Vec2 originalDir = originalBall.getDirvec();
    double angle = std::atan2(originalDir.y, originalDir.x);
    double spread = std::numbers::pi / 8;

    for (int i = 0; i < 2; ++i) {
        double newAngle = angle + (i == 0 ? -spread : spread);

        shared_ptr<Ball> newBall = std::make_shared<Ball>(originalBall);
        newBall->setDirVec(Vec2(std::cos(newAngle), std::sin(newAngle)));

        newBalls.push_back(newBall);
    }
}

void GameBoard::shootLazerOrReleaseBall() {
    if (activeBonus_ != nullptr) {
        BonusType bonusType = activeBonus_->getBonusType();
        switch (bonusType) {
        case (BonusType::Lazer):
            lazers_.emplace_back(make_shared<Lazer>(Vec2{
                racket_->getCenter().x, racket_->getTop() + LAZER_HEIGHT / 2}));
            break;
        case BonusType::StickyRacket:
            balls_.at(0)->setIsStuck(false);
            activeBonus_.reset();
            break;
        default:
            break;
        }
    }
}

void GameBoard::update(double deltaTime) {
    if (deltaTime == 0) {
        return;
    }

    handleDescendingBonuses(deltaTime);

    handleActiveBonus(deltaTime);

    handleLazers(deltaTime);

    handleBalls(deltaTime);

    updateLifeCounter();
}

void GameBoard::saveBestScore() { scoreManager_.saveScore(); }

unsigned long GameBoard::getScore() const {
    return scoreManager_.getCurrentScore();
}

const LifeCounter &GameBoard::getLife() const { return lifeCounter_; }

void GameBoard::setRacketAtX(double centerX) { racket_->setCenterX(centerX); }

const std::vector<std::shared_ptr<Ball>> &GameBoard::getBalls() const {
    return balls_;
}

const std::vector<std::shared_ptr<AbstractBrick>> &
GameBoard::getBricks() const {
    return bricks_;
}

const std::vector<std::shared_ptr<BonusPill>> &
GameBoard::getDescendingBonuses() const {
    return descendingBonuses_;
}

const Racket &GameBoard::getRacket() const { return *racket_; }

const std::vector<std::shared_ptr<Border>> &GameBoard::getBorders() const {
    return borders_;
}

const std::vector<std::shared_ptr<Lazer>> &GameBoard::getLazers() const {
    return lazers_;
}

unsigned long GameBoard::getNumBricks() const {
    return std::count_if(bricks_.begin(), bricks_.end(), [](const auto &brick) {
        return brick->getColor() != AbstractBrick::Color::gold;
    });
}

void GameBoard::resetLifeCounter() { lifeCounter_.reset(); }

void GameBoard::resetScore() { scoreManager_.resetScore(); }

unsigned long GameBoard::getBestScore() const {
    return scoreManager_.getBestScore();
}

void GameBoard::resetBestScore() { scoreManager_.resetBestScore(); }

void GameBoard::setBricks(
    const std::vector<std::shared_ptr<AbstractBrick>> &bricks) {
    bricks_ = bricks;
}

void GameBoard::setRacket(const std::shared_ptr<Racket> &racket) {
    racket_ = racket;
}

void GameBoard::setBorders(
    const std::vector<std::shared_ptr<Border>> &borders) {
    borders_ = borders;
}

void GameBoard::clearBalls() {
    balls_.clear();
    balls_.emplace_back(createBall());
}

void GameBoard::clearLazers() { lazers_.clear(); }

void GameBoard::clearActiveBonus() { activeBonus_.reset(); }

void GameBoard::clearDescendingBonuses() { descendingBonuses_.clear(); }

void GameBoard::clearBorders() { borders_.clear(); }

void GameBoard::clearBricks() { bricks_.clear(); }

void GameBoard::clear() {
    clearActiveBonus();
    clearLazers();
    clearDescendingBonuses();
    clearBalls();
    clearBorders();
    clearBricks();
}
