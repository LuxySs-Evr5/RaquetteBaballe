#include "racket.hpp"
#include "../../global_variables.hpp"
#include "../vec2/vec2.hpp"
#include <cmath>

// #### Constructors ####

Racket::Racket(const BoundingBox &boundingBox) : Bounceable(boundingBox) {}

Racket::Racket(const Vec2 &pos, double width, double height)
    : Bounceable{pos - Vec2{width / 2, height / 2},
                 pos + Vec2{width / 2, height / 2}} {}

// #### Getters ####

double Racket::getWidth() const { return boundingBox_.getWidth(); }

double Racket::getHeight() const { return boundingBox_.getHeight(); }

Vec2 Racket::getPos() const { return boundingBox_.getCenter(); }

// #### Setters ####

void Racket::setWidth(double newWidth) { boundingBox_.setWidth(newWidth); }

void Racket::setHeight(double newHeight) { boundingBox_.setHeight(newHeight); }

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
    boundingBox_.setCenter(Vec2{posX, getPos().y});
}

// #### Bounceable Override ####

Vec2 Racket::getDirVecAfterBounce(const Vec2 &closestPoint,
                                  const Vec2 &dirVec) const {
    BounceType bounceType = getBounceType(closestPoint);

    // make sure that if we hit the top edge or corner, the bounce happens the
    // racket way
    if ((bounceType == BounceType::Horizontal
         || bounceType == BounceType::Corner)
        && closestPoint.y == boundingBox_.getTop()) {

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
