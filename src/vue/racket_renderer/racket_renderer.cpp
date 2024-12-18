/**
 * @file racket_renderer.cpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief RacketRenderer class header
 * @date 18/12/2024
 * 
 */

#include "racket_renderer.hpp"
#include "../piece/racket_ui.hpp"

void RacketRenderer::render(const Racket &racket) const {
    RacketUi racketUi(racket.getBoundingBox().getCenter().toPoint(),
                      static_cast<float>(racket.getBoundingBox().getWidth()),
                      static_cast<float>(racket.getBoundingBox().getHeight()),
                      alRacketColor);

    racketUi.draw();
}
