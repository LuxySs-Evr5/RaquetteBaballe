#include "collision_solver.hpp"
#include "../../log/log.hpp"
#include "../ball/ball.hpp"
#include "../game_board/game_board.hpp"
#include "../racket/racket.hpp"

#include <memory>
#include <optional>
#include <variant>

CollisionSolver::CollisionSolver(std::shared_ptr<Racket> racket,
                                 std::vector<std::shared_ptr<Border>> &borders,
                                 std::vector<std::shared_ptr<Brick>> &bricks)
    : racket_{racket}, borders_{borders}, bricks_{bricks} {}

std::optional<std::variant<BrickIt, BorderIt, std::shared_ptr<Racket>>>
CollisionSolver::findNextCollision(Ball &ball) {
    std::optional<std::variant<BrickIt, BorderIt, std::shared_ptr<Racket>>>
        closestCollision;
    double distanceClosestCollision = std::numeric_limits<double>::max();

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

    if (racket_ && ball.checkCollision(racket_->getBoundingBox())) {
        double distanceCurrentCollision =
            ball.getUnidirectionalPenetration(racket_->getBoundingBox())
                .getModule();

        if (distanceCurrentCollision < distanceClosestCollision) {
            closestCollision = racket_;
            distanceClosestCollision = distanceCurrentCollision;
        }
    }

    return closestCollision;
}

size_t CollisionSolver::solveBallCollisions(Ball &ball) {
    size_t pointsEarned = 0;
    bool collided = true;
    do {
        auto collidingObject = (findNextCollision(ball));

        collided = collidingObject.has_value();
        if (!collided) {
            break;
        }

        if (std::holds_alternative<shared_ptr<Racket>>(
                collidingObject.value())) {
            Log::get().addMessage(Log::LogType::CollidingObject, "racket");
            shared_ptr<Racket> racket =
                std::get<shared_ptr<Racket>>(*collidingObject);
            ball.collide(*racket);
        } else if (std::holds_alternative<BrickIt>(collidingObject.value())) {
            Log::get().addMessage(Log::LogType::CollidingObject, "brick");
            BrickIt brickIt = std::get<BrickIt>(*collidingObject);
            ball.collide(*brickIt->get());
            (*brickIt)->hit();               // decrement its durability
            if ((*brickIt)->isDestroyed()) { // erase it if destroyed
                Log::get().addMessage(
                    Log::LogType::BrickDestroyed,
                    std::string{"Brick at "}
                        + string{(*brickIt)->getBoundingBox().getCenter()});
                pointsEarned += (*brickIt)->getScore();
                bricks_.erase(brickIt);
            }
        } else if (std::holds_alternative<BorderIt>(collidingObject.value())) {
            Log::get().addMessage(Log::LogType::CollidingObject, "border");
            BorderIt borderIt = std::get<BorderIt>(*collidingObject);
            ball.collide(*borderIt->get());
        }
    } while (collided);

    return pointsEarned;
}
