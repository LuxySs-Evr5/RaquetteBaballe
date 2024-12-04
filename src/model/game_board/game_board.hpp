#ifndef GAME_BOARD_HPP
#define GAME_BOARD_HPP

#include "../ball/ball.hpp"
#include "../border/border.hpp"
#include "../brick/brick.hpp"
#include "../racket/racket.hpp"

#include <memory>
#include <optional>
#include <variant>
#include <vector>

using BrickIt = std::vector<std::shared_ptr<Brick>>::const_iterator;
using BorderIt = std::vector<std::shared_ptr<Border>>::const_iterator;
using RacketIt = std::vector<std::shared_ptr<Racket>>::const_iterator;

constexpr double boardHeight = 14;
constexpr double boardWidth = 14;
constexpr double boardBoundingsThickness = 10;
constexpr double racketWidth = 2;
constexpr double racketHeight = 1;
constexpr double racketVerticalPos =
    1.5; // how high the racket is sitting on the board

class GameBoard {
  private:
    std::vector<std::shared_ptr<Ball>> balls_;

    std::vector<std::shared_ptr<Brick>> bricks_;

    // with T=thickness, H=height, W=width
    const std::vector<std::shared_ptr<Border>> borders_ = {
        // (-T, H-1 + T) -> (0,0)
        std::make_shared<Border>(
            Border{BoundingBox{Vec2{-boardBoundingsThickness,
                                    boardHeight - 1 + boardBoundingsThickness},
                              Vec2{0, 0}}}),
        // (0, H-1 + T) -> (W-1,H-1)
        std::make_shared<Border>(
            BoundingBox{Vec2{0, boardHeight -1 + boardBoundingsThickness},
                        Vec2{boardWidth-1, boardHeight-1}}),
        // (W-1, H-1 + T) -> (W-1 + T, 0)
        std::make_shared<Border>(
            BoundingBox{Vec2{boardWidth-1, boardHeight-1 + boardBoundingsThickness},
                        Vec2{boardWidth-1 + boardBoundingsThickness, 0}})};

    // Racket racket;
    // NOTE: doing this to get an iterator without having to rewrite it myself
    Racket racket_;

    std::optional<std::variant<BrickIt, BorderIt, RacketIt>>
    findNextCollision(Ball &ball);

  public:
    GameBoard(std::vector<std::shared_ptr<Ball>> balls,
              std::vector<std::shared_ptr<Brick>> bricks, Racket racket);
    
    virtual ~GameBoard() = default;

    virtual void update(double deltaTime);

    // ### Getters ###
    std::vector<std::shared_ptr<Ball>> getBalls() const;
    std::vector<std::shared_ptr<Brick>> getBricks() const;
    Racket getRackets() const;

    virtual void moveRacketHorizontal(const double x);
};

#endif
