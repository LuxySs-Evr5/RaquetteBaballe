/**
 * @file colors.hpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Define the colors used in the game
 * @date 16/11/2024
 *
 */

#ifndef COLORS_HPP
#define COLORS_HPP

#include <allegro5/color.h>

#include "../../model/brick/brick.hpp"

const ALLEGRO_COLOR COLOR_RED = al_map_rgb(255, 0, 0);
const ALLEGRO_COLOR COLOR_GREY = al_map_rgb(200, 200, 200);
const ALLEGRO_COLOR COLOR_DARK_GREY = al_map_rgb(105, 105, 105);
const ALLEGRO_COLOR COLOR_GREEN = al_map_rgb(0, 255, 0);
const ALLEGRO_COLOR COLOR_YELLOW = al_map_rgb(255, 255, 0);
const ALLEGRO_COLOR COLOR_BLACK = al_map_rgb(0, 0, 0);
const ALLEGRO_COLOR COLOR_WHITE = al_map_rgb(255, 255, 255);
const ALLEGRO_COLOR COLOR_PINK = al_map_rgb(200, 150, 167);
const ALLEGRO_COLOR COLOR_MAGENTA = al_map_rgb(255, 0, 255);
const ALLEGRO_COLOR COLOR_BLUE = al_map_rgb(0, 0, 255);
const ALLEGRO_COLOR COLOR_ORANGE = al_map_rgb(255, 165, 0);
const ALLEGRO_COLOR COLOR_CYAN = al_map_rgb(0, 255, 255);
const ALLEGRO_COLOR COLOR_SILVER = al_map_rgb(192, 192, 192);
const ALLEGRO_COLOR COLOR_GOLD = al_map_rgb(255, 215, 0);

ALLEGRO_COLOR colorToAllegroColor(Color color);

#endif // COLORS_HPP
