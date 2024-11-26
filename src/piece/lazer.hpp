/**
 * @file lazer.hpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Define the lazer class
 * @date 26/11/2024
 *
 */

#ifndef LAZER_HPP
#define LAZER_HPP

#include "../figures/forme.hpp"
#include "racket.hpp"

class Lazer final: public Rectangle{
    private:
        //TODO: Maybe remove the racket from the lazer
        Racket racket_;
        float speed_;
        
    public:
        Lazer(Racket racket);
        ~Lazer() = default;

        void moveUp();
        void draw();

        float getX() const;
        float getY() const;
        float getSpeed() const;

        void setX(const float x);
        void setY(const float y);
        void setSpeed(const float speed);

};

#endif // LAZER_HPP