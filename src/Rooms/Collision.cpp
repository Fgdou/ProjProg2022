//
// Created by guill on 19/05/2022.
//

#include <vector>
#include "Collision.h"

Collision::Collision(bool collide, Vec2 impact, Vec2 rebound) : _collide(collide), _impact(impact), _rebound(rebound)
{
}

bool Collision::isCollide() const
{
    return _collide;
}

Vec2 Collision::getImpact() const
{
    return _impact;
}

Vec2 Collision::getRebound() const
{
    return _rebound;
}

Collision Collision::getLineLineCollision(Vec2 line1Start, Vec2 line1End, Vec2 line2Start, Vec2 line2End, Vec2 reboundMulti)
{

    float x1 = line1Start.x;
    float y1 = line1Start.y;
    float x2 = line1End.x;
    float y2 = line1End.y;

    float x3 = line2Start.x;
    float y3 = line2Start.y;
    float x4 = line2End.x;
    float y4 = line2End.y;

    float uA = ((x4 - x3) * (y1 - y3) - (y4 - y3) * (x1 - x3)) / ((y4 - y3) * (x2 - x1) - (x4 - x3) * (y2 - y1));

    float uB = ((x2 - x1) * (y1 - y3) - (y2 - y1) * (x1 - x3)) / ((y4 - y3) * (x2 - x1) - (x4 - x3) * (y2 - y1));

    bool coliding = false;
    if (uA >= 0 && uA <= 1 && uB >= 0 && uB <= 1)
    {
        coliding = true;
    }

    float intersectionX = x1 + (uA * (x2 - x1));
    float intersectionY = y1 + (uA * (y2 - y1));
    return Collision(coliding, Vec2(intersectionX, intersectionY), reboundMulti);
}

Collision Collision::getLineRectCollision(Vec2 lineStart, Vec2 lineEnd, Vec2 rectTopLeft, Vec2 rectBottomRight)
{
    Collision left = getLineLineCollision(lineStart, lineEnd, Vec2(rectTopLeft.x, rectTopLeft.y), Vec2(rectTopLeft.x, rectBottomRight.y), Vec2(-1, 1));
    Collision right = getLineLineCollision(lineStart, lineEnd, Vec2(rectBottomRight.x, rectTopLeft.y), Vec2(rectBottomRight.x, rectBottomRight.y), Vec2(-1, 1));
    Collision top = getLineLineCollision(lineStart, lineEnd, Vec2(rectTopLeft.x, rectTopLeft.y), Vec2(rectBottomRight.x, rectTopLeft.y), Vec2(1, -1));
    Collision bottom = getLineLineCollision(lineStart, lineEnd, Vec2(rectTopLeft.x, rectBottomRight.y), Vec2(rectBottomRight.x, rectBottomRight.y), Vec2(1, -1));

    bool coliding = false;
    if (left.isCollide() || right.isCollide() || top.isCollide() || bottom.isCollide())
    {
        coliding = true;
    }

    // get the closest impact and rebound
    Vec2 impact(-1, -1);
    Vec2 rebound(-1, -1);

    for (Collision &col : std::vector<Collision>{left, right, top, bottom})
    {
        if (col.isCollide())
            if (impact == Vec2(-1, -1) || impact.distance(lineStart) > col.getImpact().distance(lineStart))
            {
                impact = col.getImpact();
                rebound = col.getRebound();
            }
    }

    return Collision(coliding, impact, rebound);
}

Collision Collision::getPointInsideRectCollision(Vec2 point, Vec2 rectTopLeft, Vec2 rectBottomRight)
{
    bool coliding = false;
    if (point.x >= rectTopLeft.x && point.x <= rectBottomRight.x && point.y >= rectTopLeft.y && point.y <= rectBottomRight.y)
    {
        coliding = true;
    }
    return Collision(coliding, point, Vec2(-1, -1));
}