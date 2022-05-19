//
// Created by guill on 19/05/2022.
//

#ifndef PROJPROG2022_COLLISION_H
#define PROJPROG2022_COLLISION_H

#include "../Maths/Vec2.h"

class Collision
{
protected:
    bool _collide;
    Vec2 _impact;
    Vec2 _rebound;

public:
    static Collision getLineLineCollision(Vec2 line1Start, Vec2 line1End, Vec2 line2Start, Vec2 line2End, Vec2 reboundMulti = Vec2(-1, -1));

    static Collision getLineRectCollision(Vec2 lineStart, Vec2 lineEnd, Vec2 rectTopLeft, Vec2 rectBottomRight);

    static Collision getPointInsideRectCollision(Vec2 point, Vec2 rectTopLeft, Vec2 rectBottomRight);

    Collision(bool collide, Vec2 impact, Vec2 rebound);

    bool isCollide() const;

    Vec2 getImpact() const;

    Vec2 getRebound() const;
};

#endif // PROJPROG2022_COLLISION_H
