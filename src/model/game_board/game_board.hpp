#ifndef GAME_BOARD_HPP
#define GAME_BOARD_HPP

#include "../ball/ball.hpp"
#include "../border/border.hpp"
#include "../brick/brick.hpp"
#include "../life_counter//life_counter.hpp"
#include "../racket/racket.hpp"
#include "../score_manager/score_manager.hpp"

#include <memory>
#include <optional>
#include <variant>
#include <vector>

using BrickIt = std::vector<std::shared_ptr<Brick>>::const_iterator;
using BorderIt = std::vector<std::shared_ptr<Border>>::const_iterator;
using RacketIt = std::vector<std::shared_ptr<Racket>>::const_iterator;

// TODO: move to or from globalVariables.hpp to avoid splitting variables
// everywhere

class GameBoard {
  private:
    ScoreManager scoreManager_;
    LifeCounter lifeCounter_;
    int bestScore_ = 0;

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
    void saveRecordScore();
    std::string getStringScore();
    int getScore() const;
    const LifeCounter &getLife() const;

    void setRacketAtX(double posX);

    long unsigned int getNumBricks() const;

    void resetLifeCounter();
    void resetScore();

    // #### Getters meant to be used by the View ####
    const std::vector<std::shared_ptr<Ball>> &getBalls() const;
    const std::vector<std::shared_ptr<Brick>> &getBricks() const;
    const std::vector<std::shared_ptr<Racket>> &
    getRackets() const; // TODO: set a racket and not a vector ?
    const std::vector<std::shared_ptr<Border>> &getBorders() const;
    const int getBestScore() const;


    // ### Setters to be use in controller to load a level // TODO: check
    void setBalls(const std::vector<std::shared_ptr<Ball>> balls);
    void setBricks(const std::vector<std::shared_ptr<Brick>> bricks);
    void setRacket(const std::vector<std::shared_ptr<Racket>>
                       rackets); // TODO: set a racket and not a vector
    void setBorders(const std::vector<std::shared_ptr<Border>> borders);

    // #### Get the score from the file ####
    void readBestScore();


    void resetBestScore();

    // #### Clear GameBoard ####

    void clearBalls();

    void clearBorders();

    void clearBricks();

    // TODO: might need to rename this to clearRacket (singular)
    void clearRackets();

    void clear();

    // ### Pause the game ###
    void pauseGameBoard();
};

#endif
