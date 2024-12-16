#ifndef BRICK_HPP
#define BRICK_HPP

#include "../bounceable/bounceable.hpp"
#include "../bounding_box/bounding_box.hpp"

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
    silver = 200,
    gold
};

class Brick : public Bounceable {
  protected:
    Color color_;
    uint8_t durability_;

  public:
    Brick(const BoundingBox &boundingBox, Color color,
          uint8_t durability = DURABILITY_STANDARD_BRICK);
    
    // #### Factory ####

    static std::unique_ptr<Brick> makeBrick(Color color,
                                            BoundingBox boundingBox);

    virtual ~Brick();

    // #### Brick Actions ####

    virtual void hit();

    // #### Getters ####

    virtual Color getColor() const;
    virtual size_t getScore() const;
    virtual uint8_t getDurability() const;
    virtual bool isDestroyed() const;
};

#endif
