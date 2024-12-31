#include "game_board.hpp"
#include "../../log/log.hpp"
#include "../bonus/basic_timed_bonus.hpp"
#include "../bonus/slowdown_bonus.hpp"

#include <algorithm>
#include <cstddef>
#include <iterator>
#include <memory>
#include <vector>

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
                    ball.getUnidirectionalPenetration((**it)).getModule();

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
            ball.getUnidirectionalPenetration(*racket_).getModule();

        if (distanceCurrentCollision < distanceClosestCollision) {
            closestCollision = racket_;
            distanceClosestCollision = distanceCurrentCollision;
        }
    }

    return closestCollision;
}

size_t GameBoard::handleBrickCollision(Ball &ball, BrickIt brickIt) {
    size_t pointsEarned = 0;

    ball.collide(*brickIt->get());
    BonusType bonusType =
        (*brickIt)->hit(); // decrement its durability and extract bonus
    if ((*brickIt)->isDestroyed()) {
        Log::get().addMessage(Log::LogType::BrickDestroyed,
                              std::string{"Brick at "}
                                  + string{(*brickIt)->getCenter()});

        if (bonusType != BonusType::None && numBalls() == 1) {
            Vec2 bonusPillCenter{(*brickIt)->getCenter().x,
                                 (*brickIt)->getBottom()
                                     - (BONUS_PILL_HEIGHT / 2)};
            descendingBonuses_.emplace_back(
                std::make_shared<BonusPill>(bonusPillCenter, bonusType));
        }

        pointsEarned += (*brickIt)->getScore();
        bricks_.erase(brickIt);
    }

    return pointsEarned;
}

void GameBoard::handleDescendingBonusses(double deltaTime) {
    std::vector<shared_ptr<BonusPill>> bonusesToRemove;

    for (shared_ptr<BonusPill> &descendingBonus : descendingBonuses_) {
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

size_t GameBoard::handleLazers(double deltaTime) {
    vector<shared_ptr<Lazer>> lazersToRemove;
    vector<shared_ptr<Brick>> bricksToRemove;
    size_t pointsEarned = 0;

    for (shared_ptr<Lazer> lazer : lazers_) {
        lazer->update(deltaTime);
        if (lazer->getCenter().y > 0) {
            lazersToRemove.push_back(lazer);
        }
        for (shared_ptr<Brick> brick : bricks_) {
            if (lazer->isOverlapping(*brick)) {
                if (brick->getColor() != Color::gold) {
                    bricksToRemove.push_back(brick);
                    pointsEarned += brick->getScore();
                }
                break;
            }
        }
    }

    removeSharedPointers(lazers_, lazersToRemove);
    removeSharedPointers(bricks_, bricksToRemove);

    return pointsEarned;
}

size_t GameBoard::solveBallCollisions(Ball &ball) {
    size_t pointsEarned = 0;
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

        if (prevCollidingObject.has_value()
            && collidingObject == prevCollidingObject) {
            consecutiveCollisions++;
        } else {
            consecutiveCollisions = 1;
        }

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
            pointsEarned += handleBrickCollision(ball, brickIt);
        } else if (std::holds_alternative<BorderIt>(collidingObject.value())) {
            Log::get().addMessage(Log::LogType::CollidingObject, "border");
            BorderIt borderIt = std::get<BorderIt>(*collidingObject);
            ball.collide(*borderIt->get());
        }

        prevCollidingObject = collidingObject;

    } while (collided);

    return pointsEarned;
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
        for (auto &ball : balls_) {
            ball->setSpeed(static_cast<unsigned int>(BALL_SPEED));
        }
        break;
    case BonusType::WideRacket:
        racket_->setWidth(RACKET_WIDTH);
        break;
    case BonusType::Lazer:
        lazers_.clear();
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
    double spread = M_PI / 8;

    for (int i = 0; i < 2; ++i) {
        double newAngle = angle + (i == 0 ? -spread : spread);

        shared_ptr<Ball> newBall = std::make_shared<Ball>(originalBall);
        newBall->setDirVec(Vec2(std::cos(newAngle), std::sin(newAngle)));

        newBalls.push_back(newBall);
    }
}

void GameBoard::shootLazer() {
    if (activeBonus_ != nullptr
        && activeBonus_->getBonusType() == BonusType::Lazer) {
        lazers_.emplace_back(make_shared<Lazer>(Vec2{
            racket_->getCenter().x, racket_->getTop() + LAZER_HEIGHT / 2}));
    }
}

void GameBoard::update(double deltaTime) {
    if (deltaTime == 0) {
        return;
    }

    handleDescendingBonusses(deltaTime);

    if (activeBonus_ != nullptr) {
        bool isActive = activeBonus_->update(deltaTime);
        BonusType bonusType = activeBonus_->getBonusType();
        if (bonusType == BonusType::SlowDown) {
            double slowDownFactor =
                static_cast<SlowDownBonus &>(*activeBonus_).getSlowDownFactor();

            for (auto &ball : balls_) {
                ball->setSpeed(
                    static_cast<unsigned int>(BALL_SPEED / slowDownFactor));
            }
        } else if (bonusType == BonusType::Lazer) {
            handleLazers(deltaTime);
        }

        if (!isActive) {
            undoBonusEffect(bonusType);
            activeBonus_.reset();
        }
    }

    vector<shared_ptr<Ball>> ballsToRemove;
    for (shared_ptr<Ball> ball : balls_) {
        Log::get().addMessage(Log::LogType::BallPos, ball->getCenter());

        size_t scoreToAdd = solveBallCollisions(*ball);
        scoreManager_.increaseScore(scoreToAdd);

        ball->update(deltaTime);

        if (ball->getCenter().y < -ball->getRadius()) {
            ballsToRemove.push_back(ball);
        }
    }

    removeSharedPointers(balls_, ballsToRemove);

    if (balls_.empty()) {
        --lifeCounter_;
        if (lifeCounter_ > 0) {
            balls_.emplace_back(createBall());
        }
    }
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

const std::vector<std::shared_ptr<Brick>> &GameBoard::getBricks() const {
    return bricks_;
}

const std::vector<std::shared_ptr<BonusPill>> &
GameBoard::getDescendingBonuses() const {
    return descendingBonuses_;
}

const std::shared_ptr<Racket> &GameBoard::getRacket() const { return racket_; }

const std::vector<std::shared_ptr<Border>> &GameBoard::getBorders() const {
    return borders_;
}

const std::vector<std::shared_ptr<Lazer>> &GameBoard::getLazers() const {
    return lazers_;
}

unsigned long GameBoard::getNumBricks() const {
    return std::count_if(bricks_.begin(), bricks_.end(), [](const auto &brick) {
        return brick->getColor() != Color::gold;
    });
}

void GameBoard::resetLifeCounter() { lifeCounter_.reset(); }

void GameBoard::resetScore() { scoreManager_.resetScore(); }

unsigned long GameBoard::getBestScore() const {
    return scoreManager_.getBestScore();
}

void GameBoard::resetBestScore() { scoreManager_.resetBestScore(); }

void GameBoard::setBricks(const std::vector<std::shared_ptr<Brick>> &bricks) {
    bricks_ = bricks;
}

void GameBoard::setRacket(const std::shared_ptr<Racket> racket) {
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

void GameBoard::clearBonus() { activeBonus_.reset(); }

void GameBoard::clearDescendingBonuses() { descendingBonuses_.clear(); }

void GameBoard::clearBorders() { borders_.clear(); }

void GameBoard::clearBricks() { bricks_.clear(); }

void GameBoard::clear() {
    clearBonus();
    clearDescendingBonuses();
    clearBalls();
    clearBorders();
    clearBricks();
}
