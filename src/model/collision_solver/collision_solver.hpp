#ifndef COLLISION_SOLVER_HPP
#define COLLISION_SOLVER_HPP

#include "../ball/ball.hpp"
#include "../border/border.hpp"
#include "../brick/brick.hpp"
#include "../game_board/game_board.hpp"
#include "../racket/racket.hpp"

#include <memory>
#include <optional>
#include <variant>
#include <vector>

class CollisionSolver {
  private:
    std::shared_ptr<Racket> racket_;
    std::vector<std::shared_ptr<Border>> &borders_;
    std::vector<std::shared_ptr<Brick>> &bricks_;

    std::optional<std::variant<BrickIt, BorderIt, shared_ptr<Racket>>>
    findNextCollision(Ball &ball);

  public:
    CollisionSolver(std::shared_ptr<Racket> racket,
                    std::vector<std::shared_ptr<Border>> &borders,
                    std::vector<std::shared_ptr<Brick>> &bricks);

    /**
     * @brief Resolves collisions involving the specified ball and
     * calculates the points earned from this collision resolution.
     *
     * @param ball Reference to the ball involved in the collision.
     * @return The number of points scored as a result of resolving the
     * collision.
     */
    size_t solveBallCollisions(Ball &ball);
};

#endif // COLLISION_SOLVER_HPP
