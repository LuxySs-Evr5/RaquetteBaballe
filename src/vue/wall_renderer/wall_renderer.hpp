#ifndef WALL_RENDERER_HPP
#define WALL_RENDERER_HPP

#include "../../model/border/border.hpp"
#include "../color/colors.hpp"

const ALLEGRO_COLOR alWAllColor = COLOR_GREY;

class WallRenderer {
  public:
    void render(const Border &border) const;
};

#endif
