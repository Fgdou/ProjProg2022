//
// Created by fgdou on 5/19/22.
//

#ifndef PROJPROG2022_ENTITY_H
#define PROJPROG2022_ENTITY_H


#include "../Maths/Vec2.h"

class Entity {
public:
    virtual void update() = 0;
    virtual void draw() = 0;

    virtual void setPos(const Vec2& pos) = 0;
    virtual const Vec2& getPos() = 0;
};


#endif //PROJPROG2022_ENTITY_H
