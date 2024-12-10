/**
 * @file draw_game_win.cpp
 * @author Ethan Van Ruyskensvelde (Main developper)
 * @brief Decalre drawGameOver that draws the game win message with the score
 * @date 26/11/2024
 *
 */

#include "draw_game_win.hpp"
#include "../../global_variables.hpp"
#include "../color/colors.hpp"

#include <allegro5/allegro_primitives.h>
#include <string>

using namespace std;

void drawGameWin(int score, ALLEGRO_FONT *font){
    string scoreString = "Your score is " + to_string(score);
    al_draw_filled_rectangle( GAME_OVER_RECTANGLE_X_START, GAME_OVER_RECTANGLE_Y_START, GAME_OVER_RECTANGLE_X_END, GAME_OVER_RECTANGLE_Y_END, COLOR_WHITE);
    al_draw_text(font, COLOR_BLACK, SCREEN_WIDTH / 2,GAME_OVER_RECTANGLE_Y_START + 200, ALLEGRO_ALIGN_CENTER, "YOU WIN !");
    al_draw_text(font, COLOR_BLACK, SCREEN_WIDTH / 2,GAME_OVER_RECTANGLE_Y_START + 400, ALLEGRO_ALIGN_CENTER, scoreString.c_str());

}