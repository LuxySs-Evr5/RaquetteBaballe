/**
 * @file wall_ui.hpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Define the racket class
 * @date 26/11/2024
 *
 */

#ifndef WALL_UI_HPP
#define WALL_UI_HPP

#include "../figures/forme.hpp"
#include <allegro5/color.h>

class WallUi final : public Rectangle {
  private:
    float speed_;

  public:
    WallUi();

    WallUi(Point center, float width, float height,
           ALLEGRO_COLOR = COLOR_WHITE);
    virtual ~WallUi() = default;

    void draw() override;
};

#endif // WALL_UI_HPP
