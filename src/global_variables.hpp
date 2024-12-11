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
extern const float SCREEN_WIDTH;
extern const float SCREEN_HEIGHT;
extern const double FPS;

// ### Racket ###
extern const float RACKET_THIKNESS;
extern const float RACKET_SPEED;
extern const float RACKET_WIDTH;
extern const float RACKET_HEIGHT;
extern const float RACKET_X_START;
extern const float RACKET_Y_START;

// ### Brik ###
extern const float BRIK_WIDTH;
extern const float BRIK_HEIGHT;

// ### Ball ###
extern const float BALL_RADIUS;

// ### Board ###
extern const float BOARD_WIDTH;
extern const float BOARD_HEIGHT;

// ### Walls ###
extern const float WALL_THICKNESS;
extern const float SPACE_BTW_START_SCREEN_WALL;
extern const float SPACE_FOR_TEXT_UPPER;

extern const float UPPER_WALL_Y_START;
extern const float UPPER_WALL_X_START;
extern const float LEFT_WALL_X_START;
extern const float LEFT_WALL_Y_START;
extern const float RIGHT_WALL_X_START;
extern const float RIGHT_WALL_Y_START;

// ### Lazer size ###
extern const float LAZER_WIDTH;
extern const float LAZER_HEIGHT;
extern const float LAZER_SPEED;
extern const float LAZER_Y_CENTER;

// ### Game Over message ###
extern const float GAME_OVER_RECTANGLE_WIDTH;
extern const float GAME_OVER_RECTANGLE_HEIGHT;
extern const float GAME_OVER_RECTANGLE_X_START;
extern const float GAME_OVER_RECTANGLE_Y_START;
extern const float GAME_OVER_RECTANGLE_X_END;
extern const float GAME_OVER_RECTANGLE_Y_END;

// ### Size of image heart ###
extern const float HEART_IMAGE_SIZE; // because the font size is 24

// ### Size of font ###
extern const float FONT_SIZE_24;
extern const float FONT_SIZE_50;

#endif // GLOBAL_VARIABLES_HPP
