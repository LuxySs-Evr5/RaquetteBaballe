/**
 * @file global_variables.cpp
 * @brief Definition of the global variables used in the program
 * @author Ethan Van Ruyskensvelde (Main developper)
 * @date 24/11/2024
 *
 */

#include "global_variables.hpp"

// ### Screen ###
const float SCREEN_WIDTH = 1020;
const float SCREEN_HEIGHT = 1100;
const double FPS = 60;

// ### Board ###
const float BOARD_WIDTH = 980;
const float BOARD_HEIGHT = 980;

// ### Racket ###
const float RACKET_THIKNESS = 20;
const float RACKET_SPEED = 20;
const float RACKET_WIDTH = 100;
const float RACKET_HEIGHT = 20;
const float RACKET_X_START = SCREEN_WIDTH / 2;
const float RACKET_Y_START =
    SCREEN_HEIGHT
    - 50; // 50 is the space between the end of the screen and the racket

// ### Brik ###
const float BRIK_WIDTH = 70;
const float BRIK_HEIGHT = 20;

// ### Ball ###
const float BALL_RADIUS = 10;

// ### Walls ###
const float WALL_THICKNESS = 20;
const float SPACE_BTW_START_SCREEN_WALL = 20;
const float SPACE_FOR_TEXT_UPPER = 100;

const float UPPER_WALL_Y_START = SPACE_FOR_TEXT_UPPER;
const float UPPER_WALL_X_START = SPACE_BTW_START_SCREEN_WALL;
const float LEFT_WALL_X_START = SPACE_BTW_START_SCREEN_WALL;
const float LEFT_WALL_Y_START = SPACE_FOR_TEXT_UPPER;
const float RIGHT_WALL_X_START =
    SCREEN_WIDTH - WALL_THICKNESS - SPACE_BTW_START_SCREEN_WALL;
const float RIGHT_WALL_Y_START = SPACE_FOR_TEXT_UPPER;

// ### Lazer size ###
const float LAZER_WIDTH = RACKET_WIDTH / 5;
const float LAZER_HEIGHT = 2 * LAZER_WIDTH;
const float LAZER_SPEED = 10;
const float LAZER_Y_CENTER = RACKET_Y_START - LAZER_HEIGHT / 2;

// ### Game Over message ###
const float GAME_OVER_RECTANGLE_WIDTH = BOARD_WIDTH - WALL_THICKNESS;
const float GAME_OVER_RECTANGLE_HEIGHT = BOARD_HEIGHT - WALL_THICKNESS;
const float GAME_OVER_RECTANGLE_X_START =
    SPACE_BTW_START_SCREEN_WALL + WALL_THICKNESS;
const float GAME_OVER_RECTANGLE_Y_START = SPACE_FOR_TEXT_UPPER + WALL_THICKNESS;
const float GAME_OVER_RECTANGLE_X_END =
    SCREEN_WIDTH - SPACE_BTW_START_SCREEN_WALL - WALL_THICKNESS;
const float GAME_OVER_RECTANGLE_Y_END =
    SCREEN_HEIGHT - SPACE_BTW_START_SCREEN_WALL - WALL_THICKNESS;

// ### Size of image heart ###
const float HEART_IMAGE_SIZE = 24; // because the font size is 24

// ### Size of font ###
const float FONT_SIZE_24 = 24;
const float FONT_SIZE_50 = 50;
