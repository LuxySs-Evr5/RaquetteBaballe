#ifndef MODEL_HPP
#define MODEL_HPP

#include "ball/ball.hpp"
#include "bricks/brick.hpp"

#include <memory>
#include <vector>

class Model {
  private:
    std::vector<std::shared_ptr<Ball>> balls = {
        std::make_shared<Ball>(Point{0, 0}, Point{1, 0})};

    std::vector<std::shared_ptr<Brick>> bricks{
        Brick::makeBrick(Color::red, Point{3, 0.25}, Point{5, 1}),
    };

  public:
    Model() = default;
    virtual ~Model() = default;

    virtual void update(double deltaTime);
};

#endif
