#ifndef GAME_BOARD_HPP
#define GAME_BOARD_HPP

#include "../ball/ball.hpp"
#include "../border/border.hpp"
#include "../brick/brick.hpp"

#include <memory>
#include <variant>
#include <vector>

constexpr double boardHeight = 15;
constexpr double boardWidth = 15;
constexpr double boardBoundingsThickness = 10;

class GameBoard {
  private:
    std::vector<std::shared_ptr<Ball>> balls_ = {
        std::make_shared<Ball>(Vec2{3, 3}, Vec2{1, 0}, 1)};

    std::vector<std::shared_ptr<Brick>> bricks_{
        Brick::makeBrick(Color::red, BoundingBox{Vec2{7, 5}, Vec2{10, 2}}),
        Brick::makeBrick(Color::red, BoundingBox{Vec2{10, 5}, Vec2{13, 2}}),
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

    std::variant<std::vector<std::shared_ptr<Brick>>::const_iterator,
                 std::vector<std::shared_ptr<Border>>::const_iterator>
    findNextCollision(Ball &ball);

  public:
    GameBoard() = default;
    virtual ~GameBoard() = default;

    virtual void update(double deltaTime);
};

#endif
