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

        virtual void setColor(const ALLEGRO_COLOR &color);
        virtual void setCenter(const Point center);

        virtual Point getCenter() const;
        virtual ALLEGRO_COLOR getColor() const;

        virtual void draw() = 0;
};

class Rectangle final : public Forme {
    private:
        float width_, height_;

    public:
        Rectangle(Point center, float width, float height,
                  ALLEGRO_COLOR color = COLOR_BLACK);
        
        ~Rectangle() = default;

        void draw() override;

        void setWidth(const float width);
        void setHeight(const float height);

        float getWidth() const;
        float getHeight() const;
};

class Circle final : public Forme {
    private:
        float radius_;

    public:
        Circle(Point center, float radius, ALLEGRO_COLOR color = COLOR_BLACK);

        ~Circle() = default;

        void draw() override;

        void setRadius(const float radius);

        float getRadius() const;
};

#endif // FORME_HPP