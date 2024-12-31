/**
 * @file draw_game_win.hpp
 * @author Ethan Van Ruyskensvelde (Main developper)
 * @brief Decalre drawGameWin that draws the game win message with the score
 * @date 26/11/2024
 *
 */

#ifndef DRAW_GAME_WIN_HPP
#define DRAW_GAME_WIN_HPP

#include <allegro5/allegro_font.h>

/**
 * @brief Draw the game win message with the score
 *
 * @param score The score of the player
 * @param font The font to use to draw the message
 */
void drawGameWin(unsigned long score, ALLEGRO_FONT *font);

#endif // DRAW_GAME_WIN_HPP