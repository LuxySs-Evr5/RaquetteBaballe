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
    BoundingBox(Vec2 topLeft, Vec2 bottomRight);

    // #### Destructor ####

    ~BoundingBox();

    // #### Setters ####

    void setCenter(Vec2 coordinate);

    // #### Getters ####

    Vec2 getCenter() const noexcept;

    double getWidth() const noexcept;

    double getHeight() const noexcept;

    Vec2 getTopLeft() const noexcept;

    Vec2 getTopRight() const noexcept;

    Vec2 getBottomRight() const noexcept;

    Vec2 getBottomLeft() const noexcept;
};

#endif
