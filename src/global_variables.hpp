/**
 * @file global_variables.hpp
 * @brief Definition of the global variables used in the program
 * @author Ethan Van Ruyskensvelde (Main developper)
 * @date 24/11/2024
 *
 */

#ifndef GLOBAL_VARIABLES_HPP
#define GLOBAL_VARIABLES_HPP

// ### Screen ###
#include <cstdint>
extern const float SCREEN_WIDTH;
extern const float SCREEN_HEIGHT;
extern const double FPS;

// ### Racket ###
extern const double RACKET_WIDTH;
extern const double RACKET_HEIGHT;

// ### Brick ###
extern const double BRICK_WIDTH;
extern const double BRICK_HEIGHT;

// ### Ball ###
extern const double BALL_RADIUS;
extern const double BALL_SPEED;

// ### Board ###
extern const double BOARD_WIDTH;
extern const double BOARD_HEIGHT;

// ### Walls ###
extern const double WALL_THICKNESS;

// ### Lazer size ###
extern const double LAZER_WIDTH;
extern const double LAZER_HEIGHT;
extern const double LAZER_SPEED;

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

#endif // GLOBAL_VARIABLES_HPP
