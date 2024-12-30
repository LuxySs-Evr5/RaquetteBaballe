#ifndef RECTANGLE_SHAPE_HPP
#define RECTANGLE_SHAPE_HPP

#include "../vec2/vec2.hpp"

class RectangleShape {
  private:
    Vec2 center_;
    double width_;
    double height_;

  public:
    /**
     * @brief Constructs a new RectangleShape.
     *
     * @param center The center coordinate.
     * @param width The width.
     * @param height The height.
     */
    RectangleShape(const Vec2 &center, double width, double height);

    /**
     * @brief Constructs a new RectangleShape.
     *
     * @param topLeft The top-left corner coordinate.
     * @param bottomRight The bottom-right corner coordinate.
     */
    RectangleShape(const Vec2 &topLeft, const Vec2 &bottomRight);

    RectangleShape(const RectangleShape &other) = default;
    RectangleShape(RectangleShape &&) = default;
    RectangleShape &operator=(const RectangleShape &) = default;
    RectangleShape &operator=(RectangleShape &&) = default;

    virtual ~RectangleShape() = default;

    /**
     * @brief Sets the RectangleShape's center.
     * @param centerPos The new center's position.
     */
    void setCenter(const Vec2 &centerPos);

    /**
     * @brief Sets the RectangleShape's width.
     * @param newWidth The width.
     */
    void setWidth(double newWidth);

    /**
     * @brief Sets the RectangleShape's height.
     * @param newHeight The height.
     */
    void setHeight(double newWidth);

    /**
     * @brief Returns the RectangleShape's center's position.
     */
    const Vec2 &getCenter() const noexcept;

    /**
     * @brief Returns the RectangleShape's width.
     */
    double getWidth() const noexcept;

    /**
     * @brief Returns the RectangleShape's height.
     */
    double getHeight() const noexcept;

    /**
     * @brief Returns the RectangleShape's left-edge x-coordinate.
     */
    double getLeft() const noexcept;

    /**
     * @brief Returns the RectangleShape's right-edge x-coordinate.
     */
    double getRight() const noexcept;

    /**
     * @brief Returns the RectangleShape's bottom-edge y-coordinate.
     */
    double getBottom() const noexcept;

    /**
     * @brief Returns the RectangleShape's top-edge y-coordinate.
     */
    double getTop() const noexcept;

    /**
     * @brief Returns the RectangleShape's top-left corner's coordinate.
     */
    Vec2 getTopLeft() const noexcept;

    /**
     * @brief Returns the RectangleShape's top-right corner's coordinate.
     */
    Vec2 getTopRight() const noexcept;

    /**
     * @brief Returns the RectangleShape's bottom-left corner's coordinate.
     */
    Vec2 getBottomLeft() const noexcept;

    /**
     * @brief Returns the RectangleShape's bottom-right corner's coordinate.
     */
    Vec2 getBottomRight() const noexcept;

    /**
     * @brief Returns true if overlaps with the given bounding-box.
     */
    bool isOverlapping(const RectangleShape &other);
};

#endif
