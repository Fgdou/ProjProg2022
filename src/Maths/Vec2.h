//
// Created by fgdou on 5/19/22.
//

#ifndef PROJPROG2022_VEC2_H
#define PROJPROG2022_VEC2_H


#include <memory>

class Vec2 {
public:
    Vec2();
    Vec2(const Vec2& copy);
    Vec2(double x, double y);
    Vec2(double v);

    Vec2 rotate(double radian) const;
    Vec2 normalize() const;
    double norm() const;
    double norm2() const;

    Vec2 operator+(const Vec2& other) const;
    Vec2 operator-(const Vec2& other) const;
    Vec2 operator/(double n) const;
    Vec2 operator*(double n) const;

    Vec2& operator+=(const Vec2& other);
    Vec2& operator-=(const Vec2& other);
    Vec2& operator/=(const Vec2& other);
    Vec2& operator*=(const Vec2& other);

    double distance(const Vec2& other) const;

    Vec2 screenToWorld() const;
    Vec2 WorldToScreen() const;

    double x, y;
};


#endif //PROJPROG2022_VEC2_H
