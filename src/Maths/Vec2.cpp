//
// Created by fgdou on 5/19/22.
//

#include "Vec2.h"
#include "../Renderer.h"
#include <cmath>

Vec2::Vec2()
    : x(0), y(0)
{
}

Vec2::Vec2(const Vec2 &copy)
    : x(copy.x), y(copy.y)
{
}

Vec2::Vec2(double x, double y)
    : x(x), y(y)
{
}

Vec2::Vec2(double v)
    : x(v), y(v)
{
}

double Vec2::norm2() const
{
    return x * x + y * y;
}

double Vec2::norm() const
{
    return sqrt(norm2());
}

Vec2 Vec2::normalize() const
{
    return *this / norm2();
}

bool Vec2::operator!=(const Vec2 &other)
{
    return x != other.x || y != other.y;
}

bool Vec2::operator==(const Vec2 &other)
{
    return x == other.x && y == other.y;
}

Vec2 &Vec2::operator+=(const Vec2 &other)
{
    x += other.x;
    y += other.y;
    return *this;
}

Vec2 &Vec2::operator-=(const Vec2 &other)
{
    x -= other.x;
    y -= other.y;
    return *this;
}

Vec2 &Vec2::operator/=(const Vec2 &other)
{
    x /= other.x;
    y /= other.y;
    return *this;
}

Vec2 &Vec2::operator*=(const Vec2 &other)
{
    x *= other.x;
    y *= other.y;
    return *this;
}

Vec2 Vec2::operator+(const Vec2 &other) const
{
    Vec2 v = *this;
    v += other;
    return v;
}

Vec2 Vec2::operator-(const Vec2 &other) const
{
    Vec2 v = *this;
    v -= other;
    return v;
}

Vec2 Vec2::operator/(const Vec2 &other) const
{
    Vec2 v = *this;
    v /= other;
    return v;
}

Vec2 Vec2::operator*(const Vec2 &other) const
{
    Vec2 v = *this;
    v *= other;
    return v;
}

Vec2 Vec2::screenToWorld() const
{
    auto screenSize = Renderer::getInstance().getSize();
    auto worldPos = Renderer::getInstance().getCamera().getPos();
    auto scale = Renderer::getInstance().getCamera().getScale();

    Vec2 res = *this;
    res -= screenSize / 2;
    res *= scale;

    res += worldPos;

    return res;
}
Vec2 Vec2::worldToScreen() const
{
    auto screenSize = Renderer::getInstance().getSize();
    auto worldPos = Renderer::getInstance().getCamera().getPos();
    auto scale = Renderer::getInstance().getCamera().getScale();

    Vec2 res = *this;
    res -= worldPos;
    res /= scale;
    res += screenSize / 2;

    return res;
}

double Vec2::distance(const Vec2 &other) const
{
    return (other - *this).norm();
}

Vec2 Vec2::rotate(double radian) const
{
    return {
        x * cos(radian) - y * sin(radian),
        x * sin(radian) - y * cos(radian)};
}

Vec2 Vec2::lookAt(const Vec2 &other) const
{
    return (other - *this).normalize();
}

double Vec2::angleBetween(const Vec2 &other) const
{
    auto angleMe = angle();
    auto angleOther = other.angle();

    auto res = angleOther - angleMe;
    if (res < M_PI)
        res += 2 * M_PI;
    if (res > M_PI)
        res -= 2 * M_PI;
    return res;
}

double Vec2::dot(const Vec2 &other) const
{
    return x * other.x + y * other.y;
}

double Vec2::angle() const
{
    return atan2(y, x);
}

Vec2 Vec2::screenToWorldScale() const
{
    auto scale = Renderer::getInstance().getCamera().getScale();

    Vec2 res = *this;
    res *= scale;

    return res;
}

Vec2 Vec2::worldToScreenScale() const
{
    auto scale = Renderer::getInstance().getCamera().getScale();

    Vec2 res = *this;
    res /= scale;

    return res;
}
