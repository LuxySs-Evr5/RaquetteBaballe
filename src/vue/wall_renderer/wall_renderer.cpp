/**
 * @file wall_renderer.cpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief WallRenderer class header
 * @date 18/02/2024
 *
 */

#include "wall_renderer.hpp"
#include "../piece/wall_ui.hpp"

void WallRenderer::render(const Border &border) const {
    WallUi racketUi(border.getBoundingBox().getCenter().toPoint(),
                    static_cast<float>(border.getBoundingBox().getWidth()),
                    static_cast<float>(border.getBoundingBox().getHeight()),
                    alWAllColor);

    racketUi.draw();
}
