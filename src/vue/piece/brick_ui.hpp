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

class BrickUi final : public Rectangle {
  public:
    /**
     * @brief Construct a new Brick Ui object
     * 
     * @param center The center of the brick
     * @param width The width of the brick
     * @param height The height of the brick
     * @param color The color of the brick
     */
    BrickUi(Point center, float width, float height, ALLEGRO_COLOR color);

    /**
     * @brief Destroy the Brick Ui object
     * 
     */
    virtual ~BrickUi() = default;

    /**
     * @brief Draw the brick
     * 
     */
    void draw() override;
};

#endif // BRIKUI_HPP
