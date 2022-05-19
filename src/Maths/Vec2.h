//
// Created by fgdou on 5/19/22.
//

#ifndef PROJPROG2022_VEC2_H
#define PROJPROG2022_VEC2_H


#include <memory>

class Vec2 {
public:
    Vec2 rotate(double radian);
    Vec2 normalize();
    double norm();
    double norm2();

    Vec2 operator+(const Vec2& other);
    Vec2 operator-(const Vec2& other);
    Vec2 operator/(double n);
    Vec2 operator*(double n);

    Vec2& operator+=(const Vec2& other);
    Vec2& operator-=(const Vec2& other);
    Vec2& operator/=(double n);
    Vec2& operator*=(double n);

    Vec2 screenToWorld();
    Vec2 WorldToScreen();
};


#endif //PROJPROG2022_VEC2_H
