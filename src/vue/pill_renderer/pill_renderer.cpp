/**
 * @file pill_renderer.cpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief PillRenderer class header
 * @date 18/12/2024
 * 
 */

#include "pill_renderer.hpp"
#include "../piece/bonus_pill_ui.hpp"
#include "../color/colors.hpp"
#include <allegro5/color.h>

void PillRenderer::render(const BonusPill &bonusPill) const {
    ALLEGRO_COLOR color;
    if (bonusPill.getBonusType() == BonusType::ExtraLife) {
        color = COLOR_GREY;
    }
    else if (bonusPill.getBonusType() == BonusType::SlowDown) {
        color = COLOR_ORANGE;
    }
    else if (bonusPill.getBonusType() == BonusType::WideRacket) {
        color = COLOR_BLUE;
    }

    BonusPillUi bonusPillUi(bonusPill.getCoordinate().toPoint(),
                            static_cast<float>(bonusPill.getWidth()),
                            static_cast<float>(bonusPill.getHeight()),
                            color);

    bonusPillUi.draw();
}
