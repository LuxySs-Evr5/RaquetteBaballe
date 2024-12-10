#include "colors.hpp"
#include <allegro5/color.h>

ALLEGRO_COLOR colorToAllegroColor(Color color) {
    ALLEGRO_COLOR alColor;

    switch (color) {
    case Color::white:
        alColor = COLOR_WHITE;
        break;
    case Color::orange:
        alColor = COLOR_ORANGE;
        break;
    case Color::cyan:
        alColor = COLOR_CYAN;
        break;
    case Color::green:
        alColor = COLOR_GREEN;
        break;
    case Color::red:
        alColor = COLOR_RED;
        break;
    case Color::blue:
        alColor = COLOR_BLUE;
        break;
    case Color::magenta:
        alColor = COLOR_MAGENTA;
        break;
    case Color::yellow:
        alColor = COLOR_YELLOW;
        break;
    case Color::silver:
        alColor = COLOR_SILVER;
        break;
    case Color::gold:
        alColor = COLOR_GOLD;
        break;
    default:
        alColor = COLOR_RED;
        break;
    }

    return alColor;
}
