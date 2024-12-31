/**
 * @file ball_ui.hpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Define the class BallUi
 * @date 26/11/2024
 *
 */

#ifndef BALL_UI_HPP
#define BALL_UI_HPP

#include "../figures/forme.hpp"
#include <allegro5/color.h>

class BallUi final : public Circle {
  public:
    /**
     * @brief Construct a new Ball Ui object
     *
     * @param center The center of the ball
     * @param radius The radius of the ball
     * @param color The color of the ball
     */
    BallUi(Point center, float radius, ALLEGRO_COLOR color = COLOR_BLUE);

    /**
     * @brief Destroy the Ball Ui object
     *
     */
    virtual ~BallUi() = default;

    /**
     * @brief Draw the ball
     *
     */
    virtual void draw() override;
};

#endif // BALL_UI_HPP
