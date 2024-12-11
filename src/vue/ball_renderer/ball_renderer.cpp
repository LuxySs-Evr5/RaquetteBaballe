#include "ball_renderer.hpp"

void BallRenderer::render(const Ball &ball) const {
    BallUi ballUi{ball.getCoordinate().toPoint(),
                  static_cast<float>(ball.getRadius())};

    ballUi.draw();
}
