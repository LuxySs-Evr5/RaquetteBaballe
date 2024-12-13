/**
 * @file forme.hpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Define the class parent Forme and the class fille Circle and Rectangle
 * @date 16/11/2024
 *
 */

#ifndef FORME_HPP
#define FORME_HPP

#include "../color/colors.hpp"
#include "point.hpp"
#include <allegro5/color.h>

class Rectangle {
  protected:
    Point center_;
    float width_, height_;
    ALLEGRO_COLOR fillColor_;
    ALLEGRO_COLOR frameColor_;

  public:
    Rectangle(Point center, float width, float height,
              ALLEGRO_COLOR fillColor = COLOR_BLACK, ALLEGRO_COLOR frameColor = COLOR_WHITE);

    virtual ~Rectangle() = default;

    virtual void draw();

    virtual void moveHorizontally(float x);

    virtual void setWidth(const float width);
    virtual void setHeight(const float height);

    virtual float getWidth() const;
    virtual float getHeight() const;
};

class Circle {
  protected:
    Point center_;
    float radius_;
    ALLEGRO_COLOR fillColor_;
    ALLEGRO_COLOR frameColor_;

  public:
    Circle(Point center, float radius, ALLEGRO_COLOR fillColor = COLOR_WHITE, ALLEGRO_COLOR frameColor = COLOR_BLACK);

    virtual ~Circle() = default;

    virtual void draw();

    virtual void move(const float x, const float y);

    virtual void setRadius(const float radius);

    virtual float getRadius() const;
};

#endif // FORME_HPP
