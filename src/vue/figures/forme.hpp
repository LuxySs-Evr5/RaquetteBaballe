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

class Rectangle {
  protected:
    Point center_;
    float width_, height_;
    ALLEGRO_COLOR fillColor_;
    ALLEGRO_COLOR frameColor_;

  public:
    /**
     * @brief Construct a new Rectangle object
     * 
     * @param center The center of the rectangle
     * @param width The width of the rectangle
     * @param height The height of the rectangle
     * @param fillColor The fillcolor of the rectangle 
     * @param frameColor The framecolor of the rectangle
     */
    Rectangle(Point center, float width, float height,
              ALLEGRO_COLOR fillColor = COLOR_BLACK,
              ALLEGRO_COLOR frameColor = COLOR_WHITE);

    /**
     * @brief Destroy the Rectangle object
     * 
     */
    virtual ~Rectangle() = default;

    /**
     * @brief Draw the rectangle
     * 
     */
    virtual void draw();
};

class Circle {
  protected:
    Point center_;
    float radius_;
    ALLEGRO_COLOR fillColor_;
    ALLEGRO_COLOR frameColor_;

  public:
    /**
     * @brief Construct a new Circle object
     * 
     * @param center The center of the circle
     * @param radius The radius of the circle
     * @param fillColor The fillcolor of the circle
     * @param frameColor The framecolor of the circle
     */
    Circle(Point center, float radius, ALLEGRO_COLOR fillColor = COLOR_WHITE,
           ALLEGRO_COLOR frameColor = COLOR_BLACK);

    /**
     * @brief Destroy the Circle object
     * 
     */
    virtual ~Circle() = default;
    
    /**
     * @brief Draw the circle
     * 
     */
    virtual void draw();
};

#endif // FORME_HPP
