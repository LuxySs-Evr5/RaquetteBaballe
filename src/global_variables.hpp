/**
 * @file global_variables.hpp
 * @brief Definition of the global variables used in the program
 * @author Ethan Van Ruyskensvelde (Main developper)
 * @date 24/11/2024
 *
 */

#ifndef GLOBAL_VARIABLES_HPP
#define GLOBAL_VARIABLES_HPP

#include <string>

using namespace std;

// ### Screen ###
extern const float SCREEN_WIDTH;
extern const float SCREEN_HEIGHT;
extern const double FPS;


// ### Racket ###
extern const float RACKET_SPEED;
extern const float RACKET_WIDTH;
extern const float RACKET_HEIGHT;


// ### Brik ###
extern const float BRIK_WIDTH;
extern const float BRIK_HEIGHT;


// ### Ball ###
extern const float BALL_RADIUS;


// ### Walls ###
extern const float WALL_THICKNESS;

extern const float UPPER_WALL_Y_START;
extern const float UPPER_WALL_X_START;
extern const float LEFT_WALL_X_START;
extern const float LEFT_WALL_Y_START;
extern const float RIGHT_WALL_X_START;
extern const float RIGHT_WALL_Y_START;
extern const float BOTTOM_WALL_X_START;
extern const float BOTTOM_WALL_Y_START;

extern const float SPACE_BTW_START_SCREEN_WALL;


// ### Strings ###
extern const string HEART_TEXT;


#endif // GLOBAL_VARIABLES_HPP