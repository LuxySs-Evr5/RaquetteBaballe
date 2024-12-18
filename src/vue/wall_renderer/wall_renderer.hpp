/**
 * @file wall_renderer.hpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief WallRenderer class header
 * @date 18/02/2024
 *
 */

#ifndef WALL_RENDERER_HPP
#define WALL_RENDERER_HPP

#include "../../model/border/border.hpp"
#include "../color/colors.hpp"

const ALLEGRO_COLOR alWAllColor = COLOR_GREY;

class WallRenderer {
  public:
    /**
     * @brief Transle the border to WallUI and draw it
     * 
     * @param border 
     */
    void render(const Border &border) const;
};

#endif
