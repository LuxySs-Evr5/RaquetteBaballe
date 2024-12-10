/**
 * @file main_game.hpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Class that manage the current game
 */

#ifndef CONTROLLER_GAME_HPP
#define CONTROLLER_GAME_HPP

#include <memory>

#include "../model/game_board/game_board.hpp"

using namespace std;

class ControllerGame {
  private:
    bool isGaming_ = true;
    bool win_ = false;
    bool done_ = false;
    bool draw_ = false;

    shared_ptr<GameBoard> gameBoard_;

    // ### Private Methods ###
    void drawGame();
    void checkLife();
    void checkEventType();
    void waitKeyToRestart();

  public:
    ControllerGame();
    virtual ~ControllerGame();

    // ### Public Methods ###
    void process();
};
#endif
