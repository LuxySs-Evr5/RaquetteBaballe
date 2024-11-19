#ifndef VEC2_HPP
#define VEC2_HPP

#include <iostream>

struct Vec2 {
    double x;
    double y;

    Vec2(double x, double y);

    virtual double getModule() const;

    virtual const Vec2 &normalize();

    virtual Vec2 clamped(const Vec2 &min, const Vec2 &max) const;

    virtual bool operator==(const Vec2 &other) const;

    virtual const Vec2 operator+(const Vec2 &vec) const;

    virtual const Vec2 operator+=(const Vec2 &vec);

    virtual const Vec2 operator-(const Vec2 &vec) const;

    virtual const Vec2 operator-=(const Vec2 &vec);

    virtual const Vec2 operator-() const;
    virtual const Vec2 operator*(double scalar) const;
    virtual const Vec2 operator*=(double scalar);

    friend std::ostream &operator<<(std::ostream &os, const Vec2 &p);
};

#endif
