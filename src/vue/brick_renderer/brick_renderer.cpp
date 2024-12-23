#include "brick_renderer.hpp"
#include "../../vue/piece/brick_ui.hpp"
#include "../color/colors.hpp"

void BrickRenderer::render(const Brick &brick) const {
    const ALLEGRO_COLOR brickColor = colorToAllegroColor(brick.getColor());

    BrickUi brickUi{brick.getBoundingBox().getCenter().toPoint(),
                   static_cast<float>(brick.getBoundingBox().getWidth()),
                   static_cast<float>(brick.getBoundingBox().getHeight()),
                   brickColor};

    if (brick.getDurability() == 2) {
        brickUi.setFrameColor(COLOR_BLACK); // for silver bricks change frame color for if durability is 2, if it's 1, it's default white
    }

    brickUi.draw();
}
