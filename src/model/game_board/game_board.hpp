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
                         BoundingBox{Vec2{50, 800}, Vec2{100, 775}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{125, 800}, Vec2{175, 775}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{200, 800}, Vec2{250, 775}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{275, 800}, Vec2{325, 775}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{350, 800}, Vec2{400, 775}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{425, 800}, Vec2{475, 775}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{500, 800}, Vec2{550, 775}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{575, 800}, Vec2{625, 775}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{650, 800}, Vec2{700, 775}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{725, 800}, Vec2{775, 775}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{800, 800}, Vec2{850, 775}}),


        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{50, 750}, Vec2{100, 725}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{125, 750}, Vec2{175, 725}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{200, 750}, Vec2{250, 725}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{275, 750}, Vec2{325, 725}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{350, 750}, Vec2{400, 725}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{425, 750}, Vec2{475, 725}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{500, 750}, Vec2{550, 725}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{575, 750}, Vec2{625, 725}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{650, 750}, Vec2{700, 725}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{725, 750}, Vec2{775, 725}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{800, 750}, Vec2{850, 725}}),





        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{50, 700}, Vec2{100, 675}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{125, 700}, Vec2{175, 675}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{200, 700}, Vec2{250, 675}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{275, 700}, Vec2{325, 675}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{350, 700}, Vec2{400, 675}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{425, 700}, Vec2{475, 675}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{500, 700}, Vec2{550, 675}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{575, 700}, Vec2{625, 675}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{650, 700}, Vec2{700, 675}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{725, 700}, Vec2{775, 675}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{800, 700}, Vec2{850, 675}}),







        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{50, 650}, Vec2{100, 625}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{125, 650}, Vec2{175, 625}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{200, 650}, Vec2{250, 625}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{275, 650}, Vec2{325, 625}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{350, 650}, Vec2{400, 625}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{425, 650}, Vec2{475, 625}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{500, 650}, Vec2{550, 625}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{575, 650}, Vec2{625, 625}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{650, 650}, Vec2{700, 625}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{725, 650}, Vec2{775, 625}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{800, 650}, Vec2{850, 625}}),





        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{50, 600}, Vec2{100, 575}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{125, 600}, Vec2{175, 575}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{200, 600}, Vec2{250, 575}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{275, 600}, Vec2{325, 575}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{350, 600}, Vec2{400, 575}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{425, 600}, Vec2{475, 575}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{500, 600}, Vec2{550, 575}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{575, 600}, Vec2{625, 575}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{650, 600}, Vec2{700, 575}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{725, 600}, Vec2{775, 575}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{800, 600}, Vec2{850, 575}}),






        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{50, 550}, Vec2{100, 525}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{125, 550}, Vec2{175, 525}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{200, 550}, Vec2{250, 525}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{275, 550}, Vec2{325, 525}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{350, 550}, Vec2{400, 525}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{425, 550}, Vec2{475, 525}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{500, 550}, Vec2{550, 525}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{575, 550}, Vec2{625, 525}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{650, 550}, Vec2{700, 525}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{725, 550}, Vec2{775, 525}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{800, 550}, Vec2{850, 525}}),





        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{50, 500}, Vec2{100, 475}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{125, 500}, Vec2{175, 475}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{200, 500}, Vec2{250, 475}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{275, 500}, Vec2{325, 475}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{350, 500}, Vec2{400, 475}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{425, 500}, Vec2{475, 475}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{500, 500}, Vec2{550, 475}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{575, 500}, Vec2{625, 475}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{650, 500}, Vec2{700, 475}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{725, 500}, Vec2{775, 475}}),
        Brick::makeBrick(Color::red,
                         BoundingBox{Vec2{800, 500}, Vec2{850, 475}})};
                         


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

    virtual void addScore(); // add 1 to the score if a brick is destroyed

    virtual void setRacketAtX(double posX);

    virtual int getNbBricks() const;

    virtual void resetTheLife();
    virtual void resetTheScore();

    // #### getters meant to be used by the View ####

    virtual std::vector<std::shared_ptr<Ball>> &getBalls();
    virtual std::vector<std::shared_ptr<Brick>> &getBricks();
    virtual std::shared_ptr<Racket> &getRacket();
    virtual const std::vector<std::shared_ptr<Border>> &getBorders() const;
};

#endif
