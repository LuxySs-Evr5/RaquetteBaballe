#ifndef BRICK_HPP
#define BRICK_HPP

#include "../point/point.hpp"

#include <memory>

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
    Point coord_;
    uint8_t durability_;

  public:
    // factory method
    static std::shared_ptr<Brick> makeBrick(Color color, Point coord);

    Brick(Color color, Point coord, uint8_t durability = 1);

    virtual ~Brick();

    virtual void hit();

    virtual unsigned getScore() const;
    virtual Point getCoordinate() const;
    virtual uint8_t getDurability() const;
    virtual bool isDestroyed() const;
};

#endif
