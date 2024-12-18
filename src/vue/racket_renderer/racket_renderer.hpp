/**
 * @file racket_renderer.hpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief RacketRenderer class header
 * @date 18/12/2024
 * 
 */

#ifndef RACKET_RENDERER_HPP
#define RACKET_RENDERER_HPP

#include "../../model/racket/racket.hpp"
#include "../color/colors.hpp"

const ALLEGRO_COLOR alRacketColor = COLOR_RED;

class RacketRenderer {
  public:
    /**
     * @brief Translates the racket to RacketUi and draws it
     * 
     * @param racket The racket to be drawn
     */
    void render(const Racket &racket) const;
};

#endif
