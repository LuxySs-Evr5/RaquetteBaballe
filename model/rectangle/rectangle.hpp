#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "../point/point.hpp"

class Rectangle {
  private:
    Point topLeft_;
    Point bottomRight_;

  public:
    Rectangle(Point topLeft, Point bottomRight);

    Point getTopLeft() const noexcept;
    Point getBottomRight() const noexcept;
    Point getCenter() const noexcept;
};

#endif
