/**
 * @file main_game.hpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Class that manage the current game
 */

#ifndef CONTROLLER_GAME_HPP
#define CONTROLLER_GAME_HPP

#include "../model/game_board/game_board.hpp"
#include "../vue/display_game/display_game.hpp"
#include "levels/levels.hpp"

#include <allegro5/allegro.h>
#include <bitset>

using namespace std;

class ControllerGame {
  private:
    // ### Private Variables ###
    // Game variables
    bool done_ = false;      // if the game is done
    bool draw_ = false;      // if we need to draw the game
    double lastTime_ = 0;    // last time we checked the time
    double currentTime_ = 0; // current time
    unsigned long bestScore_ = 0;      // best score of the player

    // Levels, View and Model variables
    shared_ptr<GameBoard> gameBoard_;
    shared_ptr<Levels> levels_;
    shared_ptr<DisplayGame> displayGame_;

    // Allegro variables
    ALLEGRO_TIMER *timer_;
    ALLEGRO_EVENT_QUEUE *queue_;
    ALLEGRO_EVENT event_;
    ALLEGRO_MOUSE_STATE mouseState_;

    bitset<ALLEGRO_KEY_MAX>
        key_; // table of bit for all keyboard keys set to false

    // ### Private Methods ###
    /**
     * @brief Draw the game by calling the displayGame_ draw method
     *
     */
    void drawGame();

    /**
     * @brief Check if the player has won or lost
     *
     */
    void checkWinOrLose();

    /**
     * @brief Check the type of the event
     *
     */
    void checkEventType();

    /**
     * @brief Wait for a key to be pressed to restart the game
     *
     */
    void waitKeyToRestart();

    /**
     * @brief Load a level by clearing the game board and setting the new level
     * with the class Levels
     *
     */
    void loadLevel();

    /**
     * @brief Setup allegro
     *
     */
    void setupAllegro();

  public:
    /**
     * @brief Construct and destrcut a Controller Game object
     *
     */
    ControllerGame();
    virtual ~ControllerGame();

    // ### Public Methods ###
    /**
     * @brief Function that manage the game
     *
     */
    void process();
};
#endif
