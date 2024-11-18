#ifndef VEC2_HPP
#define VEC2_HPP

struct Vec2 {
    int x;
    int y;

    Vec2(int x, int y);

    double getModule() const;

    const Vec2 &normalize();
};

#endif
