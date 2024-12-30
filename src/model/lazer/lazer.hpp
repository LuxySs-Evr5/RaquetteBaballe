#ifndef LAZER_HPP
#define LAZER_HPP

#include "../rectangle_shape/rectangle_shape.hpp"

class Lazer : public RectangleShape {
  private:
    double speed_;

  public:
    /**
     * @brief Constructs a Lazer object.
     *
     * @param center The initial center position.
     */
    Lazer(const Vec2 &center);
    Lazer(const Lazer &) = default;
    Lazer(Lazer &&) = default;

    Lazer &operator=(const Lazer &) = default;
    Lazer &operator=(Lazer &&) = default;

    /**
     * @brief Updates the Lazer's position as if it had travelled for a
     * deltaTime duration (seconds).
     * @param deltaTime The duration (seconds).
     */
    void update(double deltaTime);
};

#endif // LAZER_HPP
