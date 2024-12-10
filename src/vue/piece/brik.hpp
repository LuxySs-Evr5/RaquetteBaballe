/**
 * @file brik.hpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Define the class Brik
 * @date 27/11/2024 
 *
 */

#ifndef BRIK_HPP
#define BRIK_HPP

#include "../figures/forme.hpp"

class Brik final : public Rectangle {
    private:
        int life_;
        int scoreDestroy_;

    public:
        Brik(Point center, float width, float height, int life, int scoreDestroy, ALLEGRO_COLOR color);
        virtual ~Brik() = default;

        void draw() override;

        int getLife() const;
        int getScoreDestroy() const;

        void setLife(const int life);
};


#endif // BRIK_HPP