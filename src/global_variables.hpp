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

// ### Different paths ###
constexpr char PATH_TO_FONT[] =
    "ressources/fonts/CaskaydiaCoveNerdFontMono-Regular.ttf";
constexpr char PATH_TO_MUSIC[] = "ressources/music/arkanoid.wav";
constexpr char PATH_TO_HEART_IMAGE[] = "ressources/images/heart.png";
constexpr char PATH_TO_LEVELS[] = "ressources/levels/";

// ### Screen ###
constexpr float SCREEN_WIDTH = 1020;
constexpr float SCREEN_HEIGHT = 1080;
constexpr double FPS = 125;

// ### Board ###
constexpr double BOARD_WIDTH = 980;
constexpr double BOARD_HEIGHT = 980;
constexpr double UPS = 500;

// ### Racket ###
constexpr double RACKET_WIDTH = 100;
constexpr double RACKET_HEIGHT = 25;
constexpr double RACKET_Y_POSITION = 50;

// ### Brick ###
constexpr double BRICK_WIDTH = 70;
constexpr double BRICK_HEIGHT = 20;

// ### Ball ###
constexpr double BALL_RADIUS = 10;
constexpr double BALL_SPEED = 500;
const Vec2 BALL_INITIAL_DIRECTION{0, 1};

// ### Bonus Pill ###
constexpr double BONUS_PILL_WIDTH = 10;
constexpr double BONUS_PILL_HEIGHT = 10;
constexpr double BONUS_PILL_DESCENT_SPEED = 200;

// WideRacket
constexpr double WIDE_RACKET_WIDTH = 200;
constexpr double WIDE_RACKET_DURATION = 10;

// StickyRacket
constexpr double STICKY_RACKET_DURATION = 10;

// Lazer Bonus
constexpr double LAZER_WIDTH = 5;
constexpr double LAZER_HEIGHT = 30;
constexpr double LAZER_SPEED = 800;
constexpr double LAZER_DURATION = 10;

// SlowDown Bonus
constexpr double SLOW_DOWN_PROPORTIONAL_CONST = 0.2;
constexpr double SLOW_DOWN_DURATION = 10;

// ### Walls ###
constexpr double WALL_THICKNESS = 20;

// ### Durability of bricks ###
constexpr uint8_t DURABILITY_STANDARD_BRICK = 1;
constexpr uint8_t DURABILITY_SILVER_BRICK = 2;

// ### Initial number of lives ###
constexpr unsigned INITIAL_NUM_LIVES = 3;

// ### Size of image heart ###
constexpr float HEART_IMAGE_SIZE = 24; // because the font size is 24

// ### Size of font ###
constexpr int FONT_SIZE_24 = 24;
constexpr int FONT_SIZE_50 = 50;
constexpr int FONT_SIZE_BRICK =
    BRICK_HEIGHT - 3; // a bit smaller than the brick height to fit in the brick

#endif // GLOBAL_VARIABLES_HPP
