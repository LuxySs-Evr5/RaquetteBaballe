/**
 * @file gui_racket.hpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Define the racket class
 * @date 26/11/2024
 *
 */

#ifndef GUI_RACKET_HPP
#define GUI_RACKET_HPP

#include "../figures/forme.hpp"

class GuiRacket final: public Rectangle{
    private:
        float speed_;        
    
    public:
        GuiRacket(Point center, float width, float height, ALLEGRO_COLOR color);
        ~GuiRacket() = default;

        void draw() override;

        void moveHorizontally(const float x) override;

        Point getCenter() const override;

        float getX() const;
        float getY() const;
        float getSpeed() const;

        void setX(const float x);
        void setY(const float y);
        void setSpeed(const float speed);

};

#endif // GUI_RACKET_HPP