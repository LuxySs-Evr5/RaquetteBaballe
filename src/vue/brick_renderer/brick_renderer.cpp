#include "brick_renderer.hpp"
#include "../../vue/piece/brick_ui.hpp"
#include "../color/colors.hpp"

void BrickRenderer::render(const Brick &brick) const {
    const ALLEGRO_COLOR brickColor = colorToAllegroColor(brick.getColor());

    BrickUi brickUi{brick.getBoundingBox().getCenter().toPoint(),
                   static_cast<float>(brick.getBoundingBox().getWidth()),
                   static_cast<float>(brick.getBoundingBox().getHeight()),
                   brickColor};

    brickUi.draw();
}
