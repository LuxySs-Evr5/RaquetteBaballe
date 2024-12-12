#ifndef GAME_BOARD_HPP
#define GAME_BOARD_HPP

#include "../ball/ball.hpp"
#include "../border/border.hpp"
#include "../brick/brick.hpp"
#include "../life/life.hpp"
#include "../racket/racket.hpp"
#include "../score/score.hpp"

#include <memory>
#include <optional>
#include <variant>
#include <vector>

using BrickIt = std::vector<std::shared_ptr<Brick>>::const_iterator;
using BorderIt = std::vector<std::shared_ptr<Border>>::const_iterator;
using RacketIt = std::vector<std::shared_ptr<Racket>>::const_iterator;

constexpr double boardHeight = 900;
constexpr double boardWidth = 900;
constexpr double boardBoundingsThickness = 20;
constexpr double racketWidth = 50;
constexpr double racketHeight = 20;
constexpr double racketVerticalPos =
    1.5; // how high the racket is sitting on the board

class GameBoard {
  private:
    std::vector<std::shared_ptr<Ball>> balls_ = {
        std::make_shared<Ball>(Vec2{450, 85}, Vec2{0, 1}, 10, 500)};

    std::vector<std::shared_ptr<Brick>> bricks_{
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{400, 800}, Vec2{500, 750}})};

    // with T=thickness, H=height, W=width
    const std::vector<std::shared_ptr<Border>> borders_ = {
        // TODO: Lucas doit voir : Les murs font partie de la grille
        // (0, 0) -> (0 + boardBoundingsThickness - 1, boardHeight - 1) // left wall
        std::make_shared<Border>(
            Border{BoundingBox{Vec2{0, 0},
                               Vec2{boardBoundingsThickness - 1, boardHeight -1 }}}),
        // (0, boardHeight - 1) -> (boardWidth - 1, boardHeight - boardBoundingsThickness - 1) // upper wall
        std::make_shared<Border>(
            BoundingBox{Vec2{0, boardHeight - 1},
                        Vec2{boardWidth -1 , boardHeight - boardBoundingsThickness - 1}}),
        // (boardWidth - boardBoundingsThickness - 1, 0) -> (boardWidth - 1, boardHeight - 1) // right wall
        std::make_shared<Border>(BoundingBox{
            Vec2{boardWidth - boardBoundingsThickness -1 , 0},
            Vec2{boardWidth - 1, boardHeight - 1}})};

    // Racket racket;
    // NOTE: doing this to get an iterator without having to rewrite it myself
    std::vector<std::shared_ptr<Racket>> rackets_{
        std::make_shared<Racket>(BoundingBox{Vec2{450, 50}, 100, 25})};

    std::optional<std::variant<BrickIt, BorderIt, RacketIt>>
    findNextCollision(Ball &ball);

    Score score_;

    Life life_;

  public:
    GameBoard() = default;
    virtual ~GameBoard() = default;

    virtual void update(double deltaTime);
    virtual void saveCurrentScore();
    virtual string getStringScore();
    virtual int getIntScore();
    virtual int getLife();

    virtual void setRacketAtX(double posX);

    // #### getters meant to be used by the View ####

    virtual std::vector<std::shared_ptr<Ball>> &getBalls();
    virtual std::vector<std::shared_ptr<Brick>> &getBricks();
    virtual std::shared_ptr<Racket> &getRacket();
    virtual const std::vector<std::shared_ptr<Border>> &getBorders() const;
};

#endif
