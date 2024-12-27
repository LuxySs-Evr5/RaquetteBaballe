/**
 * @file bonus_pill_ui.hpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Class that represents the bonus pill UI.
 * @date 23/12/2024
 *
 */

#ifndef BONUS_PILL_UI_HPP
#define BONUS_PILL_UI_HPP

#include "../../model/bonus_pill/bonus_pill.hpp"
#include "../figures/forme.hpp"
#include <allegro5/color.h>

class BonusPillUi final : public Rectangle {
  public:
    /**
     * @brief Construct a new Racket Ui object
     *
     * @param center The center of the racket
     * @param width The width of the racket
     * @param height The height of the racket
     */
    BonusPillUi(Point center, float width, float height,
                ALLEGRO_COLOR = COLOR_WHITE);

    /**
     * @brief Destroy the Racket Ui object
     *
     */
    virtual ~BonusPillUi() = default;

    /**
     * @brief Draw the racket
     *
     */
    void draw(const BonusPill &bonusPill);
};

#endif // BONUS_PILL_UI_HPP
