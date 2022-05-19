//
// Created by fgdou on 5/19/22.
//

#ifndef PROJPROG2022_VEC2_H
#define PROJPROG2022_VEC2_H


#include <memory>

class Vec2 {
public:
    virtual std::shared_ptr<Vec2> rotate(double radian) = 0;
    virtual std::shared_ptr<Vec2> normalize() = 0;
    virtual double norm() = 0;
    virtual double norm2() = 0;

    virtual std::shared_ptr<Vec2> operator+(const Vec2& other) = 0;
    virtual std::shared_ptr<Vec2> operator-(const Vec2& other) = 0;
    virtual std::shared_ptr<Vec2> operator/(double n) = 0;
    virtual std::shared_ptr<Vec2> operator*(double n) = 0;

    virtual Vec2& operator+=(const Vec2& other) = 0;
    virtual Vec2& operator-=(const Vec2& other) = 0;
    virtual Vec2& operator/=(double n) = 0;
    virtual Vec2& operator*=(double n) = 0;

    virtual std::shared_ptr<Vec2> screenToWorld() = 0;
    virtual std::shared_ptr<Vec2> WorldToScreen() = 0;
};


#endif //PROJPROG2022_VEC2_H
