#ifndef BOUNDING_BOX_HPP
#define BOUNDING_BOX_HPP

#include "../vec2/vec2.hpp"

class BoundingBox final {
  private:
    Vec2 center_;
    double width_;
    double height_;

  public:
    // #### Constructors ####

    BoundingBox(Vec2 center, double width, double height);
    BoundingBox(const BoundingBox &other) = default;
    BoundingBox(Vec2 topLeft, Vec2 bottomRight);

    // #### Destructor ####

    ~BoundingBox();

    // #### Setters ####

    void setCenter(Vec2 coordinate);

    void setWidth(double newWidth);
    void setHeight(double newWidth);

    // #### Getters ####

    Vec2 getCenter() const noexcept;

    double getWidth() const noexcept;
    double getHeight() const noexcept;

    double getLeft() const noexcept;
    double getRight() const noexcept;
    double getBottom() const noexcept;
    double getTop() const noexcept;

    Vec2 getTopLeft() const noexcept;
    Vec2 getTopRight() const noexcept;
    Vec2 getBottomLeft() const noexcept;
    Vec2 getBottomRight() const noexcept;

    // #### Collisions / Collision ####

    bool isOverlapping(const BoundingBox &other);
};

#endif
