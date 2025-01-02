#include "colors.hpp"
#include <allegro5/color.h>

ALLEGRO_COLOR colorToAllegroColor(AbstractBrick::Color color) {
    ALLEGRO_COLOR alColor;

    switch (color) {
    case AbstractBrick::Color::white:
        alColor = COLOR_WHITE;
        break;
    case AbstractBrick::Color::orange:
        alColor = COLOR_ORANGE;
        break;
    case AbstractBrick::Color::cyan:
        alColor = COLOR_CYAN;
        break;
    case AbstractBrick::Color::green:
        alColor = COLOR_GREEN;
        break;
    case AbstractBrick::Color::red:
        alColor = COLOR_RED;
        break;
    case AbstractBrick::Color::blue:
        alColor = COLOR_BLUE;
        break;
    case AbstractBrick::Color::magenta:
        alColor = COLOR_MAGENTA;
        break;
    case AbstractBrick::Color::yellow:
        alColor = COLOR_YELLOW;
        break;
    case AbstractBrick::Color::silver:
        alColor = COLOR_SILVER;
        break;
    case AbstractBrick::Color::gold:
        alColor = COLOR_GOLD;
        break;
    case AbstractBrick::Color::defaultBrick:
        alColor = COLOR_RED; // We chose red as the default color
        break;
    default:
        alColor = COLOR_RED; // We chose red as the default color
        break;
    }

    return alColor;
}
