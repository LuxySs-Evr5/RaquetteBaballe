/**
 * @file gui_ball.hpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Define the class Ball
 * @date 26/11/2024
 *
 */

#ifndef GUI_BALL_HPP
#define GUI_BALL_HPP

#include "../figures/forme.hpp"

class GuiBall final: public Circle{
    private:
        float speedX_, speedY_;

    public:
      GuiBall();
      GuiBall(Point center, float radius, ALLEGRO_COLOR color);
        ~GuiBall() = default;

        virtual void draw() override;

        void moveBall(const float x = 0, const float y = 0);

        void setCenter(const int x, const int y);

        float getSpeedX() const;
        float getSpeedY() const;

        void setSpeedX(const float speedX) override;
        void setSpeedY(const float speedY) override;

};

#endif // GUI_BALL_HPP