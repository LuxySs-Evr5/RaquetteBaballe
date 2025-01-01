/**
 * @file brick_ui.hpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Define the class BrickUi
 * @date 27/11/2024
 *
 */

#ifndef BRICK_UI_HPP
#define BRICK_UI_HPP

#include "../figures/forme.hpp"

#include <allegro5/allegro_font.h>

using namespace std;

/**
 * @brief Translate the BonusType to the corresponding letter
 *
 * @param bonusType The bonus type to translate
 * @return string The corresponding letter of the bonus type
 */
string BonusTypeToLetter(const BonusType bonusType);

class BrickUi final : public Rectangle {
  private:
    size_t durability_;
    BonusType bonusType_;

  public:
    /**
     * @brief Construct a new BrickUi object
     *
     * @param center The center.
     * @param width The width.
     * @param height The height.
     * @param color The color.
     * @param durability The durability.
     * @param bonusType The bonus type.
     */
    BrickUi(Point center, float width, float height, ALLEGRO_COLOR color,
            size_t durability, BonusType bonusType);

    /**
     * @brief Destroy the BrickUi object
     */
    virtual ~BrickUi() = default;

    /**
     * @brief Draw the brick
     * @param fontBrick The font of the brick bonus
     */
    using Rectangle::draw;
    void draw(const ALLEGRO_FONT *fontBrick);
};

#endif // BRICK_UI_HPP
