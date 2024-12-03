#ifndef VEC2_HPP
#define VEC2_HPP

#include <iostream>

class Vec2 {
    double x_;
    double y_;

  public:
    Vec2();
    Vec2(double x, double y);

    virtual double getX() const noexcept;
    virtual double getY() const noexcept;

    virtual void setX(double x);
    virtual void setY(double y);

    virtual double getModule() const;

    virtual const Vec2 &normalize();

    virtual Vec2 clamped(const Vec2 &min, const Vec2 &max) const;

    virtual bool operator==(const Vec2 &other) const;

    virtual Vec2 operator+(const Vec2 &vec) const;

    virtual Vec2 &operator+=(const Vec2 &vec);

    virtual Vec2 operator-(const Vec2 &vec) const;

    virtual Vec2 &operator-=(const Vec2 &vec);

    virtual Vec2 operator-() const;

    virtual Vec2 operator*(double scalar) const;

    virtual Vec2 &operator*=(double scalar);

    friend std::ostream &operator<<(std::ostream &os, const Vec2 &p);
};

#endif
