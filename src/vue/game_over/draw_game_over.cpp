/**
 * @file draw_game_over.cpp
 * @author Ethan Van Ruyskensvelde (Main developper)
 * @brief Decalre drawGameOver that draws the game over message with the score
 * @date 26/11/2024
 *
 */

#include "draw_game_over.hpp"
#include "../../global_variables.hpp"
#include "../color/colors.hpp"

#include <allegro5/allegro_primitives.h>
#include <string>

using namespace std;

void drawGameOver(unsigned long score, ALLEGRO_FONT *font) {
    string scoreString = "Your score is " + to_string(score); 
    al_draw_filled_rectangle(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, COLOR_WHITE); // Set the background to white
    al_draw_text(font, COLOR_BLACK, SCREEN_WIDTH / 2,
                 SCREEN_HEIGHT / 2, ALLEGRO_ALIGN_CENTER,
                 "GAME OVER"); // Draw the game over message
    al_draw_text(font, COLOR_BLACK, SCREEN_WIDTH / 2,
                 SCREEN_HEIGHT / 2 + 100, ALLEGRO_ALIGN_CENTER,
                 scoreString.c_str()); // Draw the score
}