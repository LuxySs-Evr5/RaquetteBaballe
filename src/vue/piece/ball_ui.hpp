/**
 * @file ball.hpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Define the class Ball
 * @date 26/11/2024
 *
 */

#ifndef BALLUI_HPP
#define BALLUI_HPP

#include "../figures/forme.hpp"
#include <allegro5/color.h>

// TODO: can we just move all of this to the BallRenderer ?

class BallUi final : public Circle {
  public:
    BallUi(Point center, float radius, ALLEGRO_COLOR color = COLOR_BLUE);
    virtual ~BallUi() = default;

    virtual void draw() override;

    // this isn't be needed anymore
    // void moveBall(const float x = 0, const float y = 0);
};

#endif // BALLUI_HPP
