#ifndef MODEL_HPP
#define MODEL_HPP

#include "ball/ball.hpp"
#include "bricks/brick.hpp"

#include <memory>
#include <vector>

class Model {
  private:
    std::vector<std::shared_ptr<Ball>> balls = {
        std::make_shared<Ball>(Point{1, 1}, Point{0, 1})};

    std::vector<std::shared_ptr<Brick>> bricks{
        Brick::makeBrick(Color::red, Point{1, 2}),
    };

  public:
    Model() = default;
    virtual ~Model() = default;

    void run();
};

#endif
