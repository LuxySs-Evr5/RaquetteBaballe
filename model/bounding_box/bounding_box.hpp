#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "../vec2/vec2.hpp"

class BoundingBox {
  private:
    Vec2 center_;
    double width_;
    double height_;

  public:
    BoundingBox(Vec2 center, double width, double height);
    // TODO: remove this constructor, only used for testing (easier to
    // visualize)
    BoundingBox(Vec2 topLeft, Vec2 bottomRight);

    virtual ~BoundingBox();

    virtual Vec2 getCenter() const noexcept;
    virtual double getWidth() const noexcept;
    virtual double getHeight() const noexcept;
    virtual Vec2 getTopLeft() const noexcept;
    virtual Vec2 getBottomRight() const noexcept;
};

#endif
