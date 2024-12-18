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
  public:
    /**
     * @brief Construct a new Wall Ui object
     * 
     * @param center The center of the wall
     * @param width The width of the wall
     * @param height The height of the wall
     */
    WallUi(Point center, float width, float height,
           ALLEGRO_COLOR = COLOR_WHITE);

    /**
     * @brief Destroy the Wall Ui object
     * 
     */
    virtual ~WallUi() = default;

    /**
     * @brief Draw the wall
     * 
     */
    void draw() override;
};

#endif // WALL_UI_HPP
