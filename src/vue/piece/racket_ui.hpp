/**
 * @file racket.hpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Define the racket class
 * @date 26/11/2024
 *
 */

#ifndef RACKET_UI_HPP
#define RACKET_UI_HPP

#include "../figures/forme.hpp"
#include <allegro5/color.h>

class RacketUi final : public Rectangle {
  private:
    float speed_;

  public:
    RacketUi();

    RacketUi(Point center, float width, float height,
             ALLEGRO_COLOR = COLOR_WHITE);
    virtual ~RacketUi() = default;

    void draw() override;

    void moveHorizontally(const float x) override;

    Point getCenter() const;

    float getX() const;
    float getY() const;
    float getSpeed() const;

    void setX(const float x);
    void setY(const float y);
    void setSpeed(const float speed);
};

#endif // RACKET_HPP
