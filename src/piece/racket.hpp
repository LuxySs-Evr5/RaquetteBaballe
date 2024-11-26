/**
 * @file racket.hpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Define the racket class
 * @date 26/11/2024
 *
 */

#ifndef RACKET_HPP
#define RACKET_HPP

#include "../figures/forme.hpp"

class Racket final: public Rectangle{
    private:
        float speed_;        
    
    public:
        Racket();
        ~Racket() = default;

        void draw();

        float getX() const;
        float getY() const;
        float getSpeed() const;

        void setX(const float x);
        void setY(const float y);
        void setSpeed(const float speed);

};

#endif // RACKET_HPP