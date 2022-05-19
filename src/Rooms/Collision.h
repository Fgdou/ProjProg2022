//
// Created by guill on 19/05/2022.
//

#ifndef PROJPROG2022_COLLISION_H
#define PROJPROG2022_COLLISION_H

#include "../Maths/Vec2.h"

class Collision
{
protected:
    bool collide;
    Vec2 impact;
    Vec2 rebound;

public:
    Collision(bool collide, Vec2 impact, Vec2 rebound);

    bool isCollide() const;

    const Vec2 &getImpact() const;

    const Vec2 &getRebound() const;
};

#endif // PROJPROG2022_COLLISION_H
