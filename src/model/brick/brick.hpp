#ifndef BRICK_HPP
#define BRICK_HPP

#include "../../global_variables.hpp"
#include "../bonus/bonus_type.hpp"
#include "../bounceable/bounceable.hpp"
#include "../bounding_box/bounding_box.hpp"

#include <memory>

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
    BonusType bonusType_;

  public:
    Brick(const BoundingBox &boundingBox, Color color,
          uint8_t durability = DURABILITY_STANDARD_BRICK,
          BonusType bonusType = BonusType::None);

    Brick(const BoundingBox &boundingBox, Color color, BonusType bonusType = BonusType::None);

    // #### Factory ####

    static std::unique_ptr<Brick>
    makeBrick(Color color, BoundingBox boundingBox,
              BonusType bonusType = BonusType::None);

    virtual ~Brick();

    // #### Brick Actions ####

    virtual BonusType hit();

    // #### Getters ####

    virtual double getWidth() const final;

    virtual double getHeight() const final;

    virtual Vec2 getPos() const final;

    virtual Color getColor() const final;

    virtual size_t getScore() const final;

    virtual uint8_t getDurability() const final;

    virtual bool isDestroyed() const final;

    virtual BonusType getBonusType() const final;

    virtual bool hasBonus() const final;
};

#endif
