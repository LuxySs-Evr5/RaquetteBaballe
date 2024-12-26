/**
 * @file bonus_pill_ui.cpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Class that represents the bonus pill UI.
 * @date 23/12/2024
 *
 */

#include "bonus_pill_ui.hpp"
#include <allegro5/color.h>

// ### Constructor ###
BonusPillUi::BonusPillUi(Point center, float width, float height, ALLEGRO_COLOR color)
    : Rectangle(center, width, height, color) {}

// ### Public methods ###
void BonusPillUi::draw(const BonusPill &bonusPill) {
    center_.y =
        SCREEN_HEIGHT
        - center_.y; // Invert the y axis to match the screen with the backend


    if (bonusPill.getBonusType() == BonusType::ExtraLife) {
        fillColor_ = COLOR_GREY;
    }
    else if (bonusPill.getBonusType() == BonusType::SlowDown) {
        fillColor_ = COLOR_ORANGE;
    }
    else if (bonusPill.getBonusType() == BonusType::WideRacket) {
        fillColor_ = COLOR_BLUE;
    }
    else if (bonusPill.getBonusType() == BonusType::SplitBall) {
        fillColor_ = COLOR_CYAN;
    }

    frameColor_ = COLOR_BLACK; // Black frame color for all bonus pills

    Rectangle::draw();
}
