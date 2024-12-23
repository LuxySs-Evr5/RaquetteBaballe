#include "racket.hpp"
#include "../../global_variables.hpp"
#include "../vec2/vec2.hpp"
#include <cmath>

Racket::Racket(const BoundingBox &boundingBox) : Bounceable(boundingBox) {}

Racket::Racket(const Vec2 &center, double width, double height)
    : Bounceable{center - Vec2{width / 2, height / 2},
                 center + Vec2{width / 2, height / 2}} {}

// #### Getters ####

Vec2 Racket::getVelocity() const {
    return previousPosition_ - boundingBox_.getCenter();
}
double Racket::getWidth() const { return boundingBox_.getWidth(); }

double Racket::getHeight() const { return boundingBox_.getHeight(); }

Vec2 Racket::getCoordinate() const { return boundingBox_.getCenter(); }

// #### Setters ####

void Racket::setCoordinate(const Vec2 &coordinate) {
    boundingBox_.setCenter(coordinate);
}

void Racket::setPosX(double posX) {
    if (posX < WALL_THICKNESS
                   + (boundingBox_.getWidth() / 2)) { // 20 for the thikness of
                                                      // the left wall
        posX = WALL_THICKNESS + (boundingBox_.getWidth() / 2);
    }

    else if (posX
             > (BOARD_WIDTH + WALL_THICKNESS)
                   - (boundingBox_.getWidth()
                      / 2)) { // + 20 for the thikness of the left wall // TODO:
                              // change the 980 with a global variable
        posX = (BOARD_WIDTH + WALL_THICKNESS) - (boundingBox_.getWidth() / 2);
    }
    boundingBox_.setCenter(Vec2{posX, getCoordinate().y});
}

void Racket::setWidth(double newWidth) { boundingBox_.setWidth(newWidth); }

void Racket::setHeight(double newHeight) { boundingBox_.setHeight(newHeight); }

// #### Bounceable Override ####

Vec2 Racket::getDirVecAfterBounce(const Vec2 &closestPoint,
                                  const Vec2 &dirVec) const {
    BounceType bounceType = getBounceType(closestPoint);

    // make sure that if we hit the top edge or corner, the bounce happens the
    // racket way
    if ((bounceType == BounceType::Horizontal
         || bounceType == BounceType::Corner)
        && closestPoint.y == boundingBox_.getTopLeft().y) {

        Vec2 leftSide =
            boundingBox_.getCenter() - Vec2{boundingBox_.getWidth() / 2, 0};

        double distFromLeftSide = closestPoint.x - leftSide.x;

        double bounceAngle =
            30 + 120 * (1 - (distFromLeftSide / boundingBox_.getWidth()));

        // Convert bounceAngle to radians
        double bounceAngleRad = bounceAngle * M_PI / 180.0;

        double verticalComponent = sin(bounceAngleRad);
        double horizontalComponent = cos(bounceAngleRad);

        return Vec2{horizontalComponent, verticalComponent}.normalize();
    } else { // bounce on the side as if it was a usual bounceable (e.g. a
             // Brick)
        return Bounceable::getDirVecAfterBounce(closestPoint, dirVec);
    }
}
