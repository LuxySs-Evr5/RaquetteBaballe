/**
 * @file gui_lazer.hpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Define the lazer class
 * @date 26/11/2024
 *
 */

#ifndef GUI_LAZER_HPP
#define GUI_LAZER_HPP

#include "../figures/forme.hpp"
#include "gui_racket.hpp"

class GuiLazer final: public Rectangle{
    private:
        //TODO: Maybe remove the racket from the lazer
        float speed_;
        
    public:
        GuiLazer(GuiRacket racket);
        ~GuiLazer() = default;

        void moveUp();
        void draw() override;

        float getX() const;
        float getY() const;
        float getSpeed() const;

        void setX(const float x);
        void setY(const float y);
        void setSpeed(const float speed);

};

#endif // GUI_LAZER_HPP