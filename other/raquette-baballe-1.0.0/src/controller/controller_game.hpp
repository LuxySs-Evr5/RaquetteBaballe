/**
 * @file main_game.hpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Class that manage the current game
 */

#ifndef CONTROLLER_GAME_HPP
#define CONTROLLER_GAME_HPP

#include "../model/game_board/game_board.hpp"
#include "../view/display_game/display_game.hpp"
#include "level_manager/level_manager.hpp"

#include <allegro5/allegro.h>
#include <allegro5/keyboard.h>
#include <bitset>

using namespace std;

class ControllerGame {
  private:
    // Game variables
    bool done_ = false;        // if the game is done
    bool draw_ = false;        // if we need to draw the game
    uint8_t numberOfTick = 0; // number of ticks


    shared_ptr<GameBoard> gameBoard_;
    LevelManager levelManager_;
    DisplayGame displayGame_;

    // Allegro variables
    ALLEGRO_TIMER *timer_;
    ALLEGRO_EVENT_QUEUE *queue_;
    ALLEGRO_EVENT event_;
    ALLEGRO_MOUSE_STATE mouseState_;

    // Bitset for registering the keyboard key presses.
    bitset<ALLEGRO_KEY_MAX> key_;

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

    /**
     * @brief Handle the tick of the timer
     *
     */
    void handleTick();

    /**
     * @brief Wait for the player to press enter to start the game and display
     * the launchGame screen
     *
     */
    void startingGame();

  public:
    /**
     * @brief Construct and destruct a Controller Game object
     *
     */
    ControllerGame();
    virtual ~ControllerGame();

    /**
     * @brief Function that manage the game
     *
     */
    void process();
};
#endif
