/**
 * @file draw_game_over.hpp
 * @author Ethan Van Ruyskensvelde (Main developper)
 * @brief Declare drawGameOver that draws the game over message with the score
 * @date 26/11/2024
 *
 */

#ifndef DRAW_GAME_OVER_HPP
#define DRAW_GAME_OVER_HPP

#include <allegro5/allegro_font.h>

/**
 * @brief Draw the game over message with the score
 *
 * @param score The score of the player
 * @param font The font to use to draw the message
 */
void drawGameOver(unsigned long score, ALLEGRO_FONT *font);

#endif // DRAW_GAME_OVER_HPP