#include "ball_renderer.hpp"
#include "../piece/ball_ui.hpp"

void BallRenderer::render(const Ball &ball) const {
    BallUi ballUi{ball.getCoordinate().toPoint(),
                  static_cast<float>(ball.getRadius())};

    ballUi.draw();
}
