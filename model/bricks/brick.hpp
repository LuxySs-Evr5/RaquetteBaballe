#ifndef BRICK_HPP
#define BRICK_HPP

#include "../rectangle/rectangle.hpp"

#include <memory>

constexpr unsigned DURABILITY_STANDARD_BRICK = 1;
constexpr unsigned DURABILITY_SILVER_BRICK = 2;

enum class Color : size_t { // Score/Point is always positive
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
    Rectangle rectangle_;
    uint8_t durability_;

    Brick(Color color, Rectangle rectangle,
          uint8_t durability = DURABILITY_STANDARD_BRICK);

  public:
    // factory method
    static std::shared_ptr<Brick> makeBrick(Color color, Rectangle rectangle);

    virtual ~Brick();

    virtual void hit();

    virtual size_t getScore() const;
    virtual uint8_t getDurability() const;
    virtual const Rectangle &getRectangle() const;
    virtual bool isDestroyed() const;
};

#endif
