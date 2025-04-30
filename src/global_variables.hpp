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
#include <string_view>

// ### Different paths ###
inline constexpr std::string_view PATH_TO_FONT =
    "ressources/fonts/CaskaydiaCoveNerdFontMono-Regular.ttf";
inline constexpr std::string_view PATH_TO_MUSIC = "ressources/music/music.wav";
inline constexpr std::string_view PATH_TO_HEART_IMAGE = "ressources/images/heart.png";
inline constexpr std::string_view PATH_TO_LEVELS = "ressources/levels/";

// ### Screen ###
inline constexpr float SCREEN_WIDTH = 1020;
inline constexpr float SCREEN_HEIGHT = 1080;
inline constexpr double FPS = 125;

// ### Board ###
inline constexpr double BOARD_WIDTH = 980;
inline constexpr double BOARD_HEIGHT = 980;
inline constexpr double UPS = 500;

// ### Racket ###
inline constexpr double RACKET_WIDTH = 100;
inline constexpr double RACKET_HEIGHT = 25;
inline constexpr double RACKET_Y_POSITION = 50;

// ### Brick ###
inline constexpr double BRICK_WIDTH = 70;
inline constexpr double BRICK_HEIGHT = 20;

// ### Ball ###
inline constexpr double BALL_RADIUS = 10;
inline constexpr double BALL_SPEED = 500;
const Vec2 BALL_INITIAL_DIRECTION{0, 1};

// ### Bonus Pill ###
inline constexpr double BONUS_PILL_WIDTH = 10;
inline constexpr double BONUS_PILL_HEIGHT = 10;
inline constexpr double BONUS_PILL_DESCENT_SPEED = 200;

// WideRacket
inline constexpr double WIDE_RACKET_WIDTH = 200;
inline constexpr double WIDE_RACKET_DURATION = 10;

// StickyRacket
inline constexpr double STICKY_RACKET_DURATION = 10;

// Lazer Bonus
inline constexpr double LAZER_WIDTH = 5;
inline constexpr double LAZER_HEIGHT = 30;
inline constexpr double LAZER_SPEED = 800;
inline constexpr double LAZER_DURATION = 10;

// SlowDown Bonus
inline constexpr double SLOW_DOWN_PROPORTIONAL_CONST = 0.2;
inline constexpr double SLOW_DOWN_DURATION = 10;

// ### Walls ###
inline constexpr double WALL_THICKNESS = 20;

// ### Durability of bricks ###
inline constexpr uint8_t DURABILITY_STANDARD_BRICK = 1;
inline constexpr uint8_t DURABILITY_SILVER_BRICK = 2;

// ### Initial number of lives ###
inline constexpr unsigned INITIAL_NUM_LIVES = 3;

// ### Size of image heart ###
inline constexpr float HEART_IMAGE_SIZE = 24; // because the font size is 24

// ### Size of font ###
inline constexpr int FONT_SIZE_24 = 24;
inline constexpr int FONT_SIZE_50 = 50;
inline constexpr int FONT_SIZE_BRICK =
    BRICK_HEIGHT - 3; // a bit smaller than the brick height to fit in the brick

#endif // GLOBAL_VARIABLES_HPP
