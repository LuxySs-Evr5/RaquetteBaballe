/**
 * @file brick_ui.cpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Define the class BrickUi
 * @date 27/11/2024
 *
 */

#include "brick_ui.hpp"

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
    case BonusType::StickyRacket:
        return "C";
    case BonusType::SplitBall:
        return "B";
    case BonusType::Lazer:
        return "L";
    case BonusType::None:
        return "";
    default:
        return "";
    }
}

BrickUi::BrickUi(Point center, float width, float height, ALLEGRO_COLOR color,
                 size_t durability, BonusType bonusType,
                 const ALLEGRO_FONT *fontBrick)
    : Rectangle(center, width, height, color), durability_(durability),
      bonusType_(bonusType), fontBrick_(fontBrick) {}

void BrickUi::draw() {
    center_.y =
        SCREEN_HEIGHT
        - center_.y; // Invert the y axis to match the screen with the backend

    if (durability_ == 2) {
        frameColor_ =
            COLOR_BLACK; // for silver bricks change frame color for if
                         // durability is 2, if it's 1, it's default white
    }

    Rectangle::draw();

    float y = center_.y
              - static_cast<float>(BRICK_HEIGHT
                                   / 2.0); // Start at the top of the brick
    string letter = BonusTypeToLetter(bonusType_);
    if (letter != "") {
        al_draw_text(fontBrick_, COLOR_BLACK, center_.x, y,
                     ALLEGRO_ALIGN_CENTER, letter.c_str());
    }
}
