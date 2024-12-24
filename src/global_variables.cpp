/**
 * @file global_variables.cpp
 * @brief Definition of the global variables used in the program
 * @author Ethan Van Ruyskensvelde (Main developper)
 * @date 24/11/2024
 *
 */

#include "global_variables.hpp"

// ### Different paths ###
const char *PATH_TO_FONT = "ressources/fonts/CaskaydiaCoveNerdFontMono-Regular.ttf";
const char *PATH_TO_MUSIC = "ressources/music/arkanoid.wav";
const char *PATH_TO_HEART_IMAGE = "ressources/images/heart.png";
const string PATH_TO_LEVELS = "ressources/levels/";

// ### Screen ###
const float SCREEN_WIDTH = 1020;
const float SCREEN_HEIGHT = 1080;
const double FPS = 60;

// ### Board ###
const double BOARD_WIDTH = 980;
const double BOARD_HEIGHT = 980;

// ### Racket ###
const double RACKET_WIDTH = 100;
const double RACKET_HEIGHT = 25;

// ### Brick ###
const double BRICK_WIDTH = 70;
const double BRICK_HEIGHT = 20;

// ### Ball ###
const double BALL_RADIUS = 10;
const double BALL_SPEED = 500;

// ### Walls ###
const double WALL_THICKNESS = 20;

// ### Lazer size ###
const double LAZER_WIDTH = RACKET_WIDTH / 5;
const double LAZER_HEIGHT = 2 * LAZER_WIDTH;
const double LAZER_SPEED = 10;

// ### Durability of bricks ###
const uint8_t DURABILITY_STANDARD_BRICK = 1;
const uint8_t DURABILITY_SILVER_BRICK = 2;

// ### Initial number of lifes ###
const unsigned INITIAL_NUM_LIFES = 3;


// ### Size of image heart ###
const float HEART_IMAGE_SIZE = 24; // because the font size is 24

// ### Size of font ###
const int FONT_SIZE_24 = 24;
const int FONT_SIZE_50 = 50;
