/**
 * @file ball.hpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Define the class Ball
 * @date 26/11/2024
 *
 */

#ifndef BALL_HPP
#define BALL_HPP

#include "../figures/forme.hpp"

class Ball final: public Circle{
    private:
        float speedX_, speedY_;

    public:
        Ball();
        ~Ball() = default;

        virtual void draw();

        void moveBall(const float x = 0, const float y = 0);

        float getSpeedX() const;
        float getSpeedY() const;

        void setSpeedX(const float speedX);
        void setSpeedY(const float speedY);

};

#endif // BALL_HPP