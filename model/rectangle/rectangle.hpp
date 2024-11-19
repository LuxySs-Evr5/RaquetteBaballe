#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "../point/point.hpp"

class Rectangle {
  private:
    Point center_;
    size_t width_;
    size_t height_;

  public:
    Rectangle(Point center, size_t width, size_t height);

    virtual ~Rectangle();

    virtual Point getCenter() const noexcept;
    virtual size_t getWidth() const noexcept;
    virtual size_t getHeight() const noexcept;
};

#endif
