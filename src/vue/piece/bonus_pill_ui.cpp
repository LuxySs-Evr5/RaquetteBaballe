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
                         BonusPill &bonusPill)
    : Rectangle(center, width, height) {
    
    if (bonusPill.getBonusType() == BonusType::ExtraLife) {
        fillColor_ = COLOR_GREY;
    } else if (bonusPill.getBonusType() == BonusType::SlowDown) {
        fillColor_ = COLOR_ORANGE;
    } else if (bonusPill.getBonusType() == BonusType::WideRacket) {
        fillColor_ = COLOR_BLUE;
    } else if (bonusPill.getBonusType() == BonusType::SplitBall) {
        fillColor_ = COLOR_CYAN;
    }
    frameColor_ = COLOR_BLACK; // Black frame color for all bonus pills
}

void BonusPillUi::draw() {
    center_.y =
        SCREEN_HEIGHT
        - center_.y; // Invert the y axis to match the screen with the backend
    Rectangle::draw();
}
