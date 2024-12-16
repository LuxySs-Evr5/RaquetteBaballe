/**
 * @file brik.hpp
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
    BrickUi(Point center, float width, float height, ALLEGRO_COLOR color);
    virtual ~BrickUi() = default;

    void draw() override;
};

#endif // BRIKUI_HPP
