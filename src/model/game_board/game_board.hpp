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
    Score score_;
    Life life_;

    std::vector<std::shared_ptr<Racket>> rackets_;
    std::vector<std::shared_ptr<Border>> borders_;
    std::vector<std::shared_ptr<Brick>> bricks_;
    std::vector<std::shared_ptr<Ball>> balls_;

    std::optional<std::variant<BrickIt, BorderIt, RacketIt>>
    findNextCollision(Ball &ball);

  public:
    GameBoard() = default;
    ~GameBoard() = default;

    void update(double deltaTime);
    void saveCurrentScore();
    std::string getStringScore();
    int getIntScore();
    int getLife();

    void addScore(); // add 1 to the score if a brick is destroyed

    void setRacketAtX(double posX);

    long unsigned int getNbBricks() const;

    void resetTheLife();
    void resetTheScore();

    // #### getters meant to be used by the View ####

    const std::vector<std::shared_ptr<Ball>> &getBalls() const;
    const std::vector<std::shared_ptr<Brick>> &getBricks() const;
    const std::vector<std::shared_ptr<Racket>> &getRackets() const; // TODO: set a racket and not a vector ?
    const std::vector<std::shared_ptr<Border>> &getBorders() const;

    // ### Setters to be use in controller to load a level // TODO: check
    void setBalls(const std::vector<std::shared_ptr<Ball>> balls);
    void setBricks(const std::vector<std::shared_ptr<Brick>> bricks);
    void setRacket(const std::vector<std::shared_ptr<Racket>> rackets); // TODO: set a racket and not a vector
    void setBorders(const std::vector<std::shared_ptr<Border>> borders);

    // ### clear the vectors of the game board ###
    void clearVectors();

};

#endif
