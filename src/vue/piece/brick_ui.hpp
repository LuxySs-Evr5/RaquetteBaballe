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
    BrickUi(Point center, float width, float height, ALLEGRO_COLOR color,
            ALLEGRO_FONT *fontBrick);

    /**
     * @brief Destroy the Brick Ui object
     *
     */
    virtual ~BrickUi() = default;

    /**
     * @brief Draw the brick
     *
     */
    using Rectangle::draw;
    void draw(const Brick &brick);

    static const ALLEGRO_FONT *getBrickFont();
};

#endif // BRICK_UI_HPP
