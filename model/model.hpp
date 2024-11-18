#ifndef MODEL_HPP
#define MODEL_HPP

#include "ball/ball.hpp"
#include "bricks/brick.hpp"
#include "vec2/vec2.hpp"

#include <memory>
#include <vector>

class Model {
  private:
    std::vector<std::shared_ptr<Ball>> balls = {
        std::make_shared<Ball>(Point{0, 0}, Vec2{1, 0})};

    std::vector<std::shared_ptr<Brick>> bricks{
        Brick::makeBrick(Color::red, Rectangle{Point{2, 1}, Point{5, 3}}),
    };

  public:
    Model() = default;
    virtual ~Model() = default;

    virtual void update(double deltaTime);
};

#endif
