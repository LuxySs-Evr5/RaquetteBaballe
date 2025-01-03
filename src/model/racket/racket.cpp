#include "racket.hpp"
#include "../../global_variables.hpp"
#include "../vec2/vec2.hpp"
#include <cmath>

#include <numbers>


Racket::Racket(const Vec2 &center, double width, double height)
    : Bounceable{center, width, height} {}

void Racket::setCenterX(double centerX) {
    if (centerX <= WALL_THICKNESS + (getWidth() / 2)) {
        centerX = WALL_THICKNESS + (getWidth() / 2)
                  + 1; // +1 because because otherwise the racket will be by 1
                       // pixel in the wall
    }

    else if (centerX >= (BOARD_WIDTH + WALL_THICKNESS) - (getWidth() / 2)) {
        centerX = (BOARD_WIDTH + WALL_THICKNESS) - (getWidth() / 2)
                  - 1; // -1 because because otherwise the racket will be by 1
                       // pixel in the wall
    }
    setCenter(Vec2{centerX, getCenter().y});
}

Vec2 Racket::getDirVecAfterBounce(const Vec2 &closestPoint,
                                  const Vec2 &dirVec) const {
    BounceType bounceType = getBounceType(closestPoint);

    // make sure that if we hit the top edge or corner, the bounce happens the
    // racket way
    if ((bounceType == BounceType::Horizontal
         || bounceType == BounceType::Corner)
        && closestPoint.y == getTop()) {

        Vec2 leftSide = getCenter() - Vec2{getWidth() / 2, 0};

        double distFromLeftSide = closestPoint.x - leftSide.x;

        double bounceAngle = 30 + 120 * (1 - (distFromLeftSide / getWidth()));

        // Convert bounceAngle to radians
        double bounceAngleRad = bounceAngle * std::numbers::pi / 180.0;

        double verticalComponent = sin(bounceAngleRad);
        double horizontalComponent = cos(bounceAngleRad);

        return Vec2{horizontalComponent, verticalComponent}.normalize();
    } else { // bounce on the side as if it was a usual bounceable (e.g. a
             // brick)
        return Bounceable::getDirVecAfterBounce(closestPoint, dirVec);
    }
}
