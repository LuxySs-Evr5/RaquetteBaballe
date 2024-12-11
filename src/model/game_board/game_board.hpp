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

constexpr double boardHeight = 1000 - 50;
constexpr double boardWidth = 1000 - 25;
constexpr double boardBoundingsThickness = 25;
constexpr double racketWidth = 50;
constexpr double racketHeight = 20;
constexpr double racketVerticalPos =
    1.5; // how high the racket is sitting on the board

class GameBoard {
  private:
    std::vector<std::shared_ptr<Ball>> balls_ = {
        std::make_shared<Ball>(Vec2{450, 50}, Vec2{0, 1}, 10, 100)};

    std::vector<std::shared_ptr<Brick>> bricks_{
        Brick::makeBrick(Color::red, BoundingBox{Vec2{400, 400}, Vec2{500, 475}}),
        Brick::makeBrick(Color::red, BoundingBox{Vec2{550, 600}, Vec2{650, 675}}),
    };

    // with T=thickness, H=height, W=width
    const std::vector<std::shared_ptr<Border>> borders_ = {
        // (-T, H-1 + T) -> (0,0)
        std::make_shared<Border>(
            Border{BoundingBox{Vec2{-boardBoundingsThickness,
                                    boardHeight - 1 + boardBoundingsThickness},
                               Vec2{0, 0}}}),
        // (0, H-1 + T) -> (W-1,H-1)
        std::make_shared<Border>(
            BoundingBox{Vec2{0, boardHeight - 1 + boardBoundingsThickness},
                        Vec2{boardWidth - 1, boardHeight - 1}}),
        // (W-1, H-1 + T) -> (W-1 + T, 0)
        std::make_shared<Border>(BoundingBox{
            Vec2{boardWidth - 1, boardHeight - 1 + boardBoundingsThickness},
            Vec2{boardWidth - 1 + boardBoundingsThickness, 0}})};

    // Racket racket;
    // NOTE: doing this to get an iterator without having to rewrite it myself
    std::vector<std::shared_ptr<Racket>> rackets_{std::make_shared<Racket>(
        BoundingBox{Vec2{450, 25}, 100,
                    25})};

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
    virtual const std::vector<std::shared_ptr<Border>> &getBorders() const ;

};

#endif
