#ifndef MODEL_HPP
#define MODEL_HPP

#include "ball/ball.hpp"
#include "brick/brick.hpp"
#include "vec2/vec2.hpp"

#include <memory>
#include <vector>

class Model {
  private:
    std::vector<std::shared_ptr<Ball>> balls = {
        std::make_shared<Ball>(Vec2{12, 1}, Vec2{-1, 1}, 1)};

    std::vector<std::shared_ptr<Brick>> bricks{
        Brick::makeBrick(Color::red, BoundingBox{Vec2{5, 5}, Vec2{11, 2}})};

  public:
    Model() = default;
    virtual ~Model() = default;

    virtual void update(double deltaTime);
};

#endif
