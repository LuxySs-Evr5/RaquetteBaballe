#ifndef BRICK_HPP
#define BRICK_HPP

#include "../bounceable/bounceable.hpp"
#include "../bounding_box/bounding_box.hpp"

class BrikUi;

#include <memory>

constexpr unsigned DURABILITY_STANDARD_BRICK = 1;
constexpr unsigned DURABILITY_SILVER_BRICK = 2;

enum class Color : size_t { // Score/Points is always positive
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

class Brick : public Bounceable {
  protected:
    Color color_;
    uint8_t durability_;

    Brick(Color color, const BoundingBox &boundingBox,
          uint8_t durability = DURABILITY_STANDARD_BRICK);

  public:
    // factory method
    static std::shared_ptr<Brick> makeBrick(Color color,
                                            BoundingBox boundingBox);

    virtual ~Brick();

    virtual void hit();

    virtual size_t getScore() const;
    virtual uint8_t getDurability() const;
    virtual bool isDestroyed() const;

    virtual Color getColor() const;
};

#endif
