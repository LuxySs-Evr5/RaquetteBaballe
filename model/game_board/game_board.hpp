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
    std::vector<std::shared_ptr<Ball>> balls_ = {
        std::make_shared<Ball>(Vec2{7, 5}, Vec2{0, -1}, 1)};

    std::vector<std::shared_ptr<Brick>> bricks_{
        // Brick::makeBrick(Color::red, BoundingBox{Vec2{7, 5}, Vec2{10, 2}}),
        // Brick::makeBrick(Color::red, BoundingBox{Vec2{10, 5}, Vec2{13, 2}}),
    };

    // with T=thickness, H=height, W=width
    const std::vector<std::shared_ptr<Border>> borders_ = {
        // (-T, H + T) -> (0,0)
        std::make_shared<Border>(
            Border{BoundingBox{Vec2{-boardBoundingsThickness,
                                    boardHeight + boardBoundingsThickness},
                               Vec2{0, 0}}}),
        // (0, H + T) -> (W,H)
        std::make_shared<Border>(
            BoundingBox{Vec2{0, boardHeight + boardBoundingsThickness},
                        Vec2{boardWidth, boardHeight}}),
        // (W, H + T) -> (W + T, 0)
        std::make_shared<Border>(
            BoundingBox{Vec2{boardWidth, boardHeight + boardBoundingsThickness},
                        Vec2{boardWidth + boardBoundingsThickness, 0}})};

    // Racket racket;
    // NOTE: doing this to get an iterator without having to rewrite it myself
    std::vector<std::shared_ptr<Racket>> rackets_{std::make_shared<Racket>(
        BoundingBox{Vec2{boardWidth / 2, racketVerticalPos}, racketWidth,
                    racketHeight})};

    std::optional<std::variant<BrickIt, BorderIt, RacketIt>>
    findNextCollision(Ball &ball);

  public:
    GameBoard() = default;
    virtual ~GameBoard() = default;

    virtual void update(double deltaTime);
};

#endif
