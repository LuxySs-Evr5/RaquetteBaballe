#ifndef BRICK_HPP
#define BRICK_HPP

#include "../point/point.hpp"

#include <memory>

constexpr unsigned DURABILITY_STANDARD_BRICK = 1;
constexpr unsigned DURABILITY_SILVER_BRICK = 2;

enum class Color : unsigned int { // Score/Point is always positive
    defaultBrick = 1,
    white = 50,
    orange = 60,
    cyan = 70,
    green = 80,
    red = 90,
    blue = 100,
    magenta = 110,
    yellow = 120,
    silver,
    gold
};

// Abstract class for bricks
class Brick {
  protected:
    Color color_;
    Point topLeft_;
    Point bottomRight_;
    uint8_t durability_;

  public:
    // factory method
    static std::shared_ptr<Brick> makeBrick(Color color, Point topLeft,
                                            Point bottomRight);

    Brick(Color color, Point topLeft, Point bottomRight,
          uint8_t durability = DURABILITY_STANDARD_BRICK);

    virtual ~Brick();

    virtual Point getNearestPointFrom(Point point) const;

    virtual void hit();

    virtual unsigned getScore() const;
    virtual uint8_t getDurability() const;
    virtual Point getTopLeft() const;
    virtual Point getBottomRight() const;
    virtual bool isDestroyed() const;
};

#endif
