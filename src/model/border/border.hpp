#ifndef BORDER_HPP
#define BORDER_HPP

#include "../bounceable/bounceable.hpp"
#include "../bounding_box/bounding_box.hpp"

/**
 * @brief Represents a map border on which the ball can bounce.
 */
class Border final : public Bounceable {
  public:
    /**
     * @brief Constructs a new map-border.
     * @param boundingBox The BoundingBox.
     */
    Border(const BoundingBox &boundingBox);
    Border(const Border &other) = default;
    Border(Border &&) = default;
    Border &operator=(const Border &) = default;
    Border &operator=(Border &&) = default;

    virtual ~Border() = default;
};

#endif
