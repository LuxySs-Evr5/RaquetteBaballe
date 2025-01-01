/**
 * @file lazer_ui.hpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Define the class LazerUi that will be used to draw the lazer
 * @date 31/12/2024
 *
 */

/**
 * @file racket_ui.hpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Define the racketUi class
 * @date 26/11/2024
 *
 */

#ifndef LAZER_UI_HPP
#define LAZER_UI_HPP

#include "../figures/forme.hpp"

#include <allegro5/color.h>

class LazerUi final : public Rectangle {
  public:
    /**
     * @brief Construct a new Lazer Ui object
     *
     * @param center The center of the Lazer
     * @param width The width of the Lazer
     * @param height The height of the Lazer
     */
    LazerUi(Point center, float width, float height, ALLEGRO_COLOR = COLOR_RED);

    /**
     * @brief Destroy the Racket Ui object
     */
    virtual ~LazerUi() = default;

    /**
     * @brief Draw the racket
     */
    void draw() override;
};

#endif // LAZER_UI_HPP
