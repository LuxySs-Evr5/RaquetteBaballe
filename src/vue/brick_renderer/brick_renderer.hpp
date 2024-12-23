#ifndef BRICK_RENDERER_HPP
#define BRICK_RENDERER_HPP

#include "../../model/brick/brick.hpp"
#include <allegro5/allegro_font.h>

class BrickRenderer {
  ALLEGRO_FONT *font_;

  void loadFont();

  public:
    BrickRenderer();
    /**
     * @brief Transform a brick into a brickUI and draw it.
     * 
     * @param brick 
     */
    void render(const Brick &brick) const;
};

#endif
