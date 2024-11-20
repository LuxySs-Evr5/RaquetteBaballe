#ifndef BOUNDING_BOX_HPP
#define BOUNDING_BOX_HPP

#include "../vec2/vec2.hpp"
#include <variant>

enum class BoundingBoxCorner { TopLeft, TopRight, BottomLeft, BottomRight };
enum class BoundingBoxEdge { Right, Left, Up, Down };

using BoundingBoxPosition = std::variant<BoundingBoxCorner, BoundingBoxEdge>;

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

    virtual BoundingBoxPosition getPointPosition(const Vec2 &point) const;
};

#endif
