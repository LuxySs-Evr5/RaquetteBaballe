/**
 * @file brik_ui.hpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Define the class Brik
 * @date 27/11/2024
 *
 */

#ifndef BRIKUI_HPP
#define BRIKUI_HPP

#include "../figures/forme.hpp"
#include <allegro5/allegro_font.h>

using namespace std;

class BrickUi final : public Rectangle {
  private:
    ALLEGRO_FONT *fontBrick_;

  public:
    /**
     * @brief Construct a new Brick Ui object
     *
     * @param center The center of the brick
     * @param width The width of the brick
     * @param height The height of the brick
     * @param color The color of the brick
     * @param fontBrick The font of the brick bonus
     */
    BrickUi(Point center, float width, float height, ALLEGRO_COLOR color, ALLEGRO_FONT *fontBrick);

    /**
     * @brief Destroy the Brick Ui object
     *
     */
    virtual ~BrickUi() = default;

    /**
     * @brief Draw the brick
     *
     */
    void draw(const Brick &brick);

    /**
     * @brief Set the Frame Color for the brick
     *
     * @param color The color of the frame
     */
    void setFrameColor(const ALLEGRO_COLOR &color);

    /**
     * @brief Get the brick's center
     *
     * @return Point
     */
    Point getCenter() const;

    static const ALLEGRO_FONT *getBrickFont();
};

#endif // BRIKUI_HPP
