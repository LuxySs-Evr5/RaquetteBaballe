/**
 * @file main_game.hpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Class that manage the current game
 */

#ifndef CONTROLLER_GAME_HPP
#define CONTROLLER_GAME_HPP

#include <allegro5/events.h>
#include <bitset>
#include <memory>

#include "../model/game_board/game_board.hpp"
#include "../vue/display_game/display_game.hpp"

#include <allegro5/allegro.h>

using namespace std;

class ControllerGame {
  private:
    bool done_ = false;
    bool draw_ = false;
    double lastTime_ = 0;
    double currentTime_ = 0;
    int bestScore_ = 0;

    shared_ptr<GameBoard> gameBoard_;
    shared_ptr<DisplayGame> displayGame_;

    ALLEGRO_TIMER *timer_;
    ALLEGRO_EVENT_QUEUE *queue_;
    ALLEGRO_EVENT event_;
    ALLEGRO_MOUSE_STATE mouseState_;

    bitset<ALLEGRO_KEY_MAX>
        key_; // table of bit for all keyboard keys set to false

    // ### Private Methods ###
    void drawGame();
    void checkGameOver();
    void checkWin();
    void checkEventType();
    void waitKeyToRestart();
    void loadLevel();

  public:
    ControllerGame();
    virtual ~ControllerGame();

    // ### Public Methods ###
    void process();
};
#endif
