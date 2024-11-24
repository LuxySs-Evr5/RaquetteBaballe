#include "racket.hpp"
#include "../vec2/vec2.hpp"
#include <cmath>

Racket::Racket(const BoundingBox &boundingBox) : Bounceable(boundingBox) {}

double Racket::getWidth() const { return boundingBox_.getWidth(); }

const Vec2 &Racket::getCoordinate() const { return boundingBox_.getCenter(); }

void Racket::setCoordinate(const Vec2 &coordinate) {
    boundingBox_.setCenter(coordinate);
}

Vec2 Racket::getDirVecAfterBounce(const Vec2 &closestPoint,
                                  const Vec2 &dirVec) const {

    Vec2 leftSide = boundingBox_.getCenter() - Vec2{boundingBox_.getWidth(), 0};

    // TODO: closestPoint.x is technically wrong, should use the actual point
    // where it gets repositionned instead
    double bounceAngle =
        30 + 120 * (1 - (closestPoint.x / boundingBox_.getWidth()));

    double verticalComponent = sin(bounceAngle);
    double horizontalComponent = cos(bounceAngle);

    return Vec2{horizontalComponent, verticalComponent}.normalize();
}
