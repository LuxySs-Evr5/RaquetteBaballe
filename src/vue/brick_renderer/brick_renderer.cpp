#include "brick_renderer.hpp"
#include "../../vue/piece/brik_ui.hpp"

void BrickRenderer::render(const Brick &brick) const {
    ALLEGRO_COLOR alBrickColor;
    switch (brick.getColor()) {

    case Color::defaultBrick:
        alBrickColor = COLOR_RED;
        break;
    case Color::white:
        alBrickColor = COLOR_WHITE;
        break;
    case Color::orange:
        alBrickColor = COLOR_ORANGE;
        break;
    case Color::cyan:
        alBrickColor = COLOR_CYAN;
        break;
    case Color::green:
        alBrickColor = COLOR_GREEN;
        break;
    case Color::red:
        alBrickColor = COLOR_RED;
        break;
    case Color::blue:
        alBrickColor = COLOR_BLUE;
        break;
    case Color::magenta:
        alBrickColor = COLOR_MAGENTA;
        break;
    case Color::yellow:
        alBrickColor = COLOR_YELLOW;
        break;
    case Color::silver:
        alBrickColor = COLOR_SILVER;
        break;
    case Color::gold:
        alBrickColor = COLOR_GOLD;
        break;
    }

    BrikUi brickUi{brick.getBoundingBox().getCenter().toPoint(),
                   static_cast<float>(brick.getBoundingBox().getWidth()),
                   static_cast<float>(brick.getBoundingBox().getHeight()),
                   alBrickColor};
}
