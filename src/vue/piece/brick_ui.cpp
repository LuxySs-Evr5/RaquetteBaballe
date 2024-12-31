/**
 * @file brick_ui.cpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Define the class BrickUi
 * @date 27/11/2024
 *
 */

#include "brick_ui.hpp"
#include "../../model/brick/brick.hpp"

string BonusTypeToLetter(const BonusType bonusType) {
    /**
     * @brief Translate the BonusType to the corresponding letter
     *
     * @param bonusType The BonusType
     * @return The corresponding letter
     */
    switch (bonusType) {
    case BonusType::ExtraLife:
        return "E";
    case BonusType::SlowDown:
        return "S";
    case BonusType::WideRacket:
        return "W";
    case BonusType::SplitBall:
        return "B";
    case BonusType::None:
        return "";
    default:
        return "";
    }
}

BrickUi::BrickUi(Point center, float width, float height, ALLEGRO_COLOR color,
                 ALLEGRO_FONT *fontBrick)
    : Rectangle(center, width, height, color), fontBrick_(fontBrick) {}

void BrickUi::draw(const Brick &brick) {
    center_.y =
        SCREEN_HEIGHT
        - center_.y; // Invert the y axis to match the screen with the backend

    if (brick.getDurability() == 2) {
        frameColor_ =
            COLOR_BLACK; // for silver bricks change frame color for if
                         // durability is 2, if it's 1, it's default white
    }

    Rectangle::draw();

    if (brick.hasBonus()) {
        float y = center_.y
                  - static_cast<float>(BRICK_HEIGHT
                                       / 2.0); // Sart at the top of the brick
        string letter = BonusTypeToLetter(brick.getBonusType());
        if (letter != "") {
            al_draw_text(
                fontBrick_, COLOR_BLACK, center_.x, y, ALLEGRO_ALIGN_CENTER,
                letter.c_str()); // draw a B in the center of the brick if it has a bonus
        }
    }
}