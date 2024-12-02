/**
 * @file draw_game_over.hpp
 * @author Ethan Van Ruyskensvelde (Main developper)
 * @brief Decalre drawGameOver that draws the game over message with the score
 * @date 26/11/2024
 *
 */

#ifndef DRAW_GAME_OVER_HPP
#define DRAW_GAME_OVER_HPP

#include <allegro5/allegro_font.h>

void drawGameOver(int score, ALLEGRO_FONT *font);

#endif // DRAW_GAME_OVER_HPP