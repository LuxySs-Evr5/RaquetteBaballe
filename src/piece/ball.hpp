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

        virtual void draw() override;

        void moveBall(const float x = 0, const float y = 0);

        float getSpeedX() const;
        float getSpeedY() const;

        void setSpeedX(const float speedX) override;
        void setSpeedY(const float speedY) override;

};

#endif // BALL_HPP