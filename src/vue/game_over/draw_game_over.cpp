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

void drawGameOver(int score, ALLEGRO_FONT *font) {
    string scoreString = "Your score is " + to_string(score);
    // TODO : maybe change the size of the rectangle of the game over message
    al_draw_filled_rectangle(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, COLOR_WHITE);
    al_draw_text(font, COLOR_BLACK, SCREEN_WIDTH / 2,
                 GAME_OVER_RECTANGLE_Y_START + 200, ALLEGRO_ALIGN_CENTER,
                 "GAME OVER");
    al_draw_text(font, COLOR_BLACK, SCREEN_WIDTH / 2,
                 GAME_OVER_RECTANGLE_Y_START + 400, ALLEGRO_ALIGN_CENTER,
                 scoreString.c_str());
}