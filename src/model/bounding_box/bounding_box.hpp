#ifndef BOUNDING_BOX_HPP
#define BOUNDING_BOX_HPP

#include "../vec2/vec2.hpp"

class BoundingBox final {
  private:
    Vec2 center_;
    double width_;
    double height_;

  public:
    /**
     * @brief Constructs a new BoundingBox.
     *
     * @param center The center coordinate.
     * @param width The width.
     * @param height The height.
     */
    BoundingBox(const Vec2 &center, double width, double height);

    /**
     * @brief Constructs a new BoundingBox.
     *
     * @param topLeft The top-left corner coordinate.
     * @param bottomRight The bottom-right corner coordinate.
     */
    BoundingBox(const Vec2 &topLeft, const Vec2 &bottomRight);
    BoundingBox(const BoundingBox &other) = default;
    BoundingBox(BoundingBox &&) = default;
    BoundingBox &operator=(const BoundingBox &) = default;
    BoundingBox &operator=(BoundingBox &&) = default;

    virtual ~BoundingBox() = default;

    /**
     * @brief Sets the BoundingBox's center.
     * @param centerPos The new center's position.
     */
    void setCenter(const Vec2 &centerPos);

    /**
     * @brief Sets the BoundingBox's width.
     * @param newWidth The width.
     */
    void setWidth(double newWidth);

    /**
     * @brief Sets the BoundingBox's height.
     * @param newHeight The height.
     */
    void setHeight(double newWidth);

    /**
     * @brief Returns the BoundingBox's center's position.
     */
    const Vec2 &getCenter() const noexcept;

    /**
     * @brief Returns the BoundingBox's width.
     */
    double getWidth() const noexcept;

    /**
     * @brief Returns the BoundingBox's height.
     */
    double getHeight() const noexcept;

    /**
     * @brief Returns the BoundingBox's left-edge x-coordinate.
     */
    double getLeft() const noexcept;

    /**
     * @brief Returns the BoundingBox's right-edge x-coordinate.
     */
    double getRight() const noexcept;

    /**
     * @brief Returns the BoundingBox's bottom-edge y-coordinate.
     */
    double getBottom() const noexcept;

    /**
     * @brief Returns the BoundingBox's top-edge y-coordinate.
     */
    double getTop() const noexcept;

    /**
     * @brief Returns the BoundingBox's top-left corner's coordinate.
     */
    Vec2 getTopLeft() const noexcept;

    /**
     * @brief Returns the BoundingBox's top-right corner's coordinate.
     */
    Vec2 getTopRight() const noexcept;

    /**
     * @brief Returns the BoundingBox's bottom-left corner's coordinate.
     */
    Vec2 getBottomLeft() const noexcept;

    /**
     * @brief Returns the BoundingBox's bottom-right corner's coordinate.
     */
    Vec2 getBottomRight() const noexcept;

    /**
     * @brief Returns true if overlaps with the given bounding-box.
     */
    bool isOverlapping(const BoundingBox &other);
};

#endif
