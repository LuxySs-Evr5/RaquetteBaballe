/**
 * @file rectangle.hpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Define the Rectangle class
 * @date 16/11/2024
 *
 */

#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "point.hpp"
#include "../colors/colors.hpp"

class Rectangle {
    private:
        Point center_;
        float width_, height_;
        ALLEGRO_COLOR color_;

    public:
      Rectangle(Point center, float width, float height,
                ALLEGRO_COLOR color = COLOR_BLACK);
      
      ~Rectangle();

      void draw();

      void setColor(const ALLEGRO_COLOR &color);
      void setCenter(const Point center);
      void setWidth(const float width);
      void setHeight(const float height);

      Point getCenter() const;
      float getWidth() const;
      float getHeight() const;
      ALLEGRO_COLOR getColor() const;

}; 

#endif // RECTANGLE_HPP