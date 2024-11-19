#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "../point/point.hpp"

class Rectangle {
  private:
    Point center_;
    double width_;
    double height_;

  public:
    Rectangle(Point center, double width, double height);
    // TODO: remove this constructor, only used for testing (easier to
    // visualize)
    Rectangle(Point topLeft, Point bottomRight);

    virtual ~Rectangle();

    virtual Point getCenter() const noexcept;
    virtual double getWidth() const noexcept;
    virtual double getHeight() const noexcept;
    virtual Point getTopLeft() const noexcept;
    virtual Point getBottomRight() const noexcept;
};

#endif
