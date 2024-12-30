/**
 * @file global_variables.hpp
 * @brief Definition of the global variables used in the program
 * @author Ethan Van Ruyskensvelde (Main developper)
 * @date 24/11/2024
 *
 */

#ifndef GLOBAL_VARIABLES_HPP
#define GLOBAL_VARIABLES_HPP

#include "model/vec2/vec2.hpp"

#include <cstdint>
#include <string>

using std::string;

// ### Different paths ###
extern const char *PATH_TO_FONT;
extern const char *PATH_TO_MUSIC;
extern const char *PATH_TO_HEART_IMAGE;
extern const string PATH_TO_LEVELS;

// ### Screen ###
extern const float SCREEN_WIDTH;
extern const float SCREEN_HEIGHT;
extern const double FPS;

// ### Board ###
extern const double BOARD_WIDTH;
extern const double BOARD_HEIGHT;
extern const double UPS;

// ### Racket ###
extern const double RACKET_WIDTH;
extern const double RACKET_HEIGHT;
extern const double RACKET_Y_POSITION;

// ### Brick ###
extern const double BRICK_WIDTH;
extern const double BRICK_HEIGHT;

// ### Ball ###
extern const double BALL_RADIUS;
extern const double BALL_SPEED;
extern const Vec2 BALL_INITIAL_DIRECTION;

// ### Bonus Pill ###
extern const double BONUS_PILL_WIDTH;
extern const double BONUS_PILL_HEIGHT;
extern const double BONUS_PILL_DESCENT_SPEED;

// ### Walls ###
extern const double WALL_THICKNESS;

// ### Durability of bricks ###
extern const uint8_t DURABILITY_STANDARD_BRICK;
extern const uint8_t DURABILITY_SILVER_BRICK;

// ### Initial number of lifes ###
extern const unsigned INITIAL_NUM_LIFES;

// ### Size of image heart ###
extern const float HEART_IMAGE_SIZE; // because the font size is 24

// ### Size of font ###
extern const int FONT_SIZE_24;
extern const int FONT_SIZE_50;
extern const int FONT_SIZE_BRICK;

#endif // GLOBAL_VARIABLES_HPP
