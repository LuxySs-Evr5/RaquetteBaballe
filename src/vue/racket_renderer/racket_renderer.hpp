#ifndef RACKET_RENDERER_HPP
#define RACKET_RENDERER_HPP

#include "../../model/racket/racket.hpp"
#include "../color/colors.hpp"
const ALLEGRO_COLOR alRacketColor = COLOR_RED;

class RacketRenderer {
  public:
    void render(const Racket &racket) const;
};

#endif
