/**
 * @file racket_ui.hpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Define the racketUi class
 * @date 26/11/2024
 *
 */

#ifndef RACKET_UI_HPP
#define RACKET_UI_HPP

#include "../figures/forme.hpp"
#include <allegro5/color.h>

class RacketUi final : public Rectangle {
  public:
    /**
     * @brief Construct a new Racket Ui object
     *
     * @param center The center of the racket
     * @param width The width of the racket
     * @param height The height of the racket
     */
    RacketUi(Point center, float width, float height,
             ALLEGRO_COLOR = COLOR_WHITE);

    /**
     * @brief Destroy the Racket Ui object
     */
    virtual ~RacketUi() = default;

    /**
     * @brief Draw the racket
     */
    void draw() override;
};

#endif // RACKET_UI_HPP
