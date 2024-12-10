/**
 * @file brik.hpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Define the class Brik
 * @date 27/11/2024 
 *
 */

#ifndef BRIKUI_HPP
#define BRIKUI_HPP

#include "../figures/forme.hpp"

class BrikUi final : public Rectangle {
    private:
        int life_;
        int scoreDestroy_;

    public:
        BrikUi(Point center, float width, float height, int life, int scoreDestroy, ALLEGRO_COLOR color);
        virtual ~BrikUi() = default;

        void draw() override;

        int getLife() const;
        int getScoreDestroy() const;

        void setLife(const int life);
};


#endif // BRIKUI_HPP