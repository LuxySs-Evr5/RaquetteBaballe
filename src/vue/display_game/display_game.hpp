/**
 * @file display_game.hpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Class that manage the display of the game
 * @date 02/12/2024
 *
 */

#ifndef DISPLAY_GAME_HPP
#define DISPLAY_GAME_HPP

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_audio.h>

#include <allegro5/display.h>
#include <string>

#include "../../model/game_board.hpp"
#include "../canvas/canvas.hpp"

class DisplayGame {
private:
  GameBoard gameBoard_;
  Canvas canvas_;

  ALLEGRO_DISPLAY *display_;
  ALLEGRO_BITMAP *heartImage_;
  ALLEGRO_SAMPLE *music_;
  ALLEGRO_SAMPLE_INSTANCE *instanceMusic_;
  ALLEGRO_FONT *font24_;
  ALLEGRO_FONT *font50_;

  // ### Private Methods ###
  void checkInit(void *test, string type);
  void initialize_allegro();

public:
  DisplayGame();
  ~DisplayGame();

  // ### Public Methods ###
  void draw();
  void gameOver();

  // ### Getters ###
  ALLEGRO_DISPLAY *getDisplay() const;

  
  
};


#endif // DISPLAY_GAME_HPP