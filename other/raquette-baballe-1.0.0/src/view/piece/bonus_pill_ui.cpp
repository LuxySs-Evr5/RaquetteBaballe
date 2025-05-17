/**
 * @file bonus_pill_ui.cpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Class that represents the bonus pill UI.
 * @date 23/12/2024
 *
 */

#include "bonus_pill_ui.hpp"

#include <allegro5/color.h>

BonusPillUi::BonusPillUi(Point center, float width, float height,
                         BonusType bonusType)
    : Rectangle(center, width, height) {

    if (bonusType == BonusType::ExtraLife) {
        fillColor_ = COLOR_GREY;
    } else if (bonusType == BonusType::SlowDown) {
        fillColor_ = COLOR_ORANGE;
    } else if (bonusType == BonusType::WideRacket) {
        fillColor_ = COLOR_BLUE;
    } else if (bonusType == BonusType::SplitBall) {
        fillColor_ = COLOR_CYAN;
    } else if (bonusType == BonusType::Lazer) {
        fillColor_ = COLOR_MAGENTA;
    } else if (bonusType == BonusType::StickyRacket) {
        fillColor_ = COLOR_GREEN;
    }
    frameColor_ = COLOR_BLACK; // Black frame color for all bonus pills
}

void BonusPillUi::draw() {
    center_.y =
        SCREEN_HEIGHT
        - center_.y; // Invert the y axis to match the screen with the backend
    Rectangle::draw();
}
