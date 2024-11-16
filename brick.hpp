#include "point.hpp"
#include <cstdint>

enum class Color : unsigned { // Score/Point is always positive
    defaultBrick = 1,
    white = 50,
    orange = 60,
    cyan = 70,
    green = 80,
    red = 90,
    blue = 100,
    magenta = 110,
    yellow = 120
};

class Brick {
  protected:
    uint8_t durability_;
    Point coord_;

  public:
    Brick(uint8_t durability, unsigned score)
        : durability_(durability), score_(score) {}

    virtual ~Brick() = default;

    virtual void hit() { // this is default behavior
        if (durability_ > 0) {
            durability_--;
        }
    }

    virtual uint8_t getDurability() const { return durability_; }
    virtual unsigned getScore() const { return score_; }
    virtual bool isDestroyed() const { return durability_ == 0; }
};

class ColoredBrick : public Brick {
    Color color_;

  public:
    ColoredBrick(Color color)
        : Brick(1, static_cast<unsigned>(color)), color_(color) {}
};

class SilverBrick : public Brick {
  public:
    SilverBrick() : Brick(2, 200) {}
};

class GoldBrick : public Brick {
  public:
    GoldBrick() : Brick(1, 0) {}

    void update() override {} // Gold bricks are never destroyed
};
