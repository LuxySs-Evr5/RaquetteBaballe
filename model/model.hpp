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
        std::make_shared<Ball>(Vec2{2, 2}, Vec2{1, 0}, 2)};

    std::vector<std::shared_ptr<Brick>> bricks{
        Brick::makeBrick(Color::red, BoundingBox{Vec2{4, 0}, Vec2{6, 4}})};

  public:
    Model() = default;
    virtual ~Model() = default;

    virtual void update(double deltaTime);
};

#endif
