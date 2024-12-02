/**
 * @file forme.hpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Define the class parent Forme and the class fille Circle and Rectangle
 * @date 16/11/2024
 *
 */

#ifndef FORME_HPP
#define FORME_HPP

#include "point.hpp"
#include "../colors/colors.hpp"

class Forme {
    protected:
        Point center_;
        ALLEGRO_COLOR color_;

    public:
        Forme(Point center, ALLEGRO_COLOR color = COLOR_BLACK);
        virtual ~Forme() = default;

        virtual void move(const float x, const float y);

        virtual void setColor(const ALLEGRO_COLOR &color);
        virtual void setCenter(const Point center);

        virtual Point getCenter() const;
        virtual ALLEGRO_COLOR getColor() const;

        virtual void draw() = 0;
};

class Rectangle : public virtual Forme {
    private:
        float width_, height_;

    public:
        Rectangle(Point center, float width, float height,
                  ALLEGRO_COLOR color = COLOR_BLACK);
        
        virtual ~Rectangle() = default;

        virtual void draw() override;

        virtual void moveHorizontally(float x);

        virtual void setWidth(const float width);
        virtual void setHeight(const float height);

        virtual float getWidth() const;
        virtual float getHeight() const;
};

class Circle : public virtual Forme {
    private:
        float radius_;
        float speedX_, speedY_;

    public:
        Circle(Point center, float radius, ALLEGRO_COLOR color = COLOR_BLACK);

        virtual ~Circle() = default;

        virtual void draw() override;

        virtual void move(const float x, const float y) override;

        virtual void setSpeedX(const float speedX);

        virtual void setSpeedY(const float speedY);
        
        virtual void setRadius(const float radius);

        virtual float getRadius() const;
};

#endif // FORME_HPP