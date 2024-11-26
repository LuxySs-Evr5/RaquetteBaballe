/**
 * @file wall_game.hpp
 * author Ethan Van Ruyskensvelde (Main developper)
 * @brief Declare the function that draws the walls of the game
 * @date 24/11/2024
 *
 */

#include "wall_game.hpp"
#include "../global_variables.hpp"

#include <allegro5/allegro_primitives.h>
#include <allegro5/color.h>

void drawWallGame(ALLEGRO_COLOR color){
    // draw the walls of the game
    al_draw_filled_rectangle(UPPER_WALL_X_START, UPPER_WALL_Y_START, SCREEN_WIDTH - SPACE_BTW_START_SCREEN_WALL, UPPER_WALL_Y_START + WALL_THICKNESS, color); // upper wall
    al_draw_filled_rectangle(LEFT_WALL_X_START, LEFT_WALL_Y_START, LEFT_WALL_X_START + WALL_THICKNESS, SCREEN_HEIGHT - SPACE_BTW_START_SCREEN_WALL, color); // left wall
    al_draw_filled_rectangle(RIGHT_WALL_X_START, RIGHT_WALL_Y_START, RIGHT_WALL_X_START + WALL_THICKNESS, SCREEN_HEIGHT - SPACE_BTW_START_SCREEN_WALL, color); // right wall
    al_draw_filled_rectangle(BOTTOM_WALL_X_START, BOTTOM_WALL_Y_START, SCREEN_WIDTH - SPACE_BTW_START_SCREEN_WALL, BOTTOM_WALL_Y_START + WALL_THICKNESS, color); // bottom wall
}