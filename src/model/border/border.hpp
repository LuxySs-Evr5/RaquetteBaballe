#ifndef BORDER_HPP
#define BORDER_HPP

#include "../bounceable/bounceable.hpp"

/**
 * @brief Represents a map border on which the ball can bounce.
 */
class Border final : public Bounceable {
  public:
    /**
     * @brief Constructs a new Border.
     *
     * @param center The center coordinate.
     * @param width The width.
     * @param height The height.
     */
    Border(const Vec2 &center, double width, double height);

    /**
     * @brief Constructs a new Border.
     *
     * @param topLeft The top-left corner coordinate.
     * @param bottomRight The bottom-right corner coordinate.
     */
    Border(const Vec2 &topLeft, const Vec2 &bottomRight);

    Border(const Border &other) = default;
    Border(Border &&) = default;
    Border &operator=(const Border &) = default;
    Border &operator=(Border &&) = default;

    virtual ~Border() = default;
};

#endif
