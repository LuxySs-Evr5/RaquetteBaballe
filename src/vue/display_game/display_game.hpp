/**
 * @file display_game.hpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Class that manage the display of the game
 * @date 02/12/2024
 *
 */

#ifndef DISPLAY_GAME_HPP
#define DISPLAY_GAME_HPP

#include "../../model/game_board/game_board.hpp"
#include "../canvas/canvas.hpp"

#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_font.h>

class DisplayGame {
  private:
    shared_ptr<GameBoard> gameBoard_;
    Canvas canvas_;

    ALLEGRO_DISPLAY *display_;
    ALLEGRO_BITMAP *heartImage_;
    ALLEGRO_SAMPLE *music_;
    ALLEGRO_SAMPLE_INSTANCE *instanceMusic_;
    ALLEGRO_FONT *font24_;
    ALLEGRO_FONT *font50_;

    // ### Private Methods ###
    /**
     * @brief Check if the initialization of the object is correct
     * 
     * @param test the thing to test
     * @param type to cerr the type of the thing that failed 
     */
    void checkInit(void *test, string type);

    /**
     * @brief Initialize allegro
     * 
     */
    void initialize_allegro();

    /**
     * @brief Draw the hearts for the remaining lifes
     * 
     */
    void drawLife();

  public:
    /**
     * @brief Construct a new Display Game object
     * 
     * @param gameBoard the game board
     */
    DisplayGame(shared_ptr<GameBoard> gameBoard);

    /**
     * @brief Destroy the Display Game object
     * 
     */
    ~DisplayGame();

    // ### Public Methods ###
    /**
     * @brief Draw the game by calling the draw method of the canvas
     * 
     */
    void draw();

    /**
     * @brief Draw the game over screen
     * 
     */
    void gameOver();

    /**
     * @brief Draw the game win screen
     * 
     */
    void gameWin();

    // ### Getters ###
    /**
     * @brief Get the ALLLEGRO_DISPLAY
     * 
     * @return ALLEGRO_DISPLAY* the ALLEGRO_DISPLAY
     */
    ALLEGRO_DISPLAY *getDisplay() const;
};

#endif // DISPLAY_GAME_HPP
