#include "racket.hpp"
#include "../vec2/vec2.hpp"
#include <cmath>

Racket::Racket(const BoundingBox &boundingBox) : Bounceable(boundingBox) {}

Racket::Racket(const Vec2 &center, double width, double height)
    : Bounceable{center - Vec2{width / 2, height / 2},
                 center + Vec2{width / 2, height / 2}} {}

double Racket::getWidth() const { return boundingBox_.getWidth(); }
double Racket::getHeight() const { return boundingBox_.getHeight(); }

Vec2 Racket::getCoordinate() const { return boundingBox_.getCenter(); }

void Racket::setCoordinate(const Vec2 &coordinate) {
    boundingBox_.setCenter(coordinate);
}

Vec2 Racket::getDirVecAfterBounce(const Vec2 &closestPoint,
                                  const Vec2 &dirVec) const {
    BounceType bounceType = getBounceType(closestPoint);

    // make sure we hit the top edge to decide to bounce the racket way
    if (bounceType == BounceType::Horizontal
        and closestPoint.y == boundingBox_.getTopLeft().y) {

        Vec2 leftSide =
            boundingBox_.getCenter() - Vec2{boundingBox_.getWidth() / 2, 0};

        double distFromLeftSide = closestPoint.x - leftSide.x;
        std::cout << "distFromLeftSide : " << distFromLeftSide << std::endl;

        double bounceAngle =
            30 + 120 * (1 - (distFromLeftSide / boundingBox_.getWidth()));
        std::cout << "bounceAngle : " << bounceAngle << std::endl;

        // Convert bounceAngle to radians
        double bounceAngleRad = bounceAngle * M_PI / 180.0;

        double verticalComponent = sin(bounceAngleRad);
        double horizontalComponent = cos(bounceAngleRad);

        return Vec2{horizontalComponent, verticalComponent}.normalize();
    } else { // bounce on the side as if it was a usual bounceable like a Brick
        std::cout << "doing normal bounce on the racket's side" << std::endl;
        return Bounceable::getDirVecAfterBounce(closestPoint, dirVec);
    }
}

void Racket::setPosX(double posX) {
    boundingBox_.setCenter(Vec2{posX, getCoordinate().y});
}

RacketUi Racket::toRaketUi() const {
    return RacketUi{boundingBox_.getCenter().toPoint(),
                    static_cast<float>(getWidth()),
                    static_cast<float>(getHeight())};
}
