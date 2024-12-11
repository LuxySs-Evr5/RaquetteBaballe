#ifndef RACKET_RENDERER_HPP
#define RACKET_RENDERER_HPP

#include "../../model/racket/racket.hpp"
#include <allegro5/color.h>

const ALLEGRO_COLOR alRacketColor = COLOR_RED;

class RacketRenderer {
  public:
    void render(const Racket &racket) const;
};

#endif
