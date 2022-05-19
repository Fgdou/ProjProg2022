//
// Created by fgdou on 5/19/22.
//

#ifndef PROJPROG2022_ENTITY_H
#define PROJPROG2022_ENTITY_H


#include "../Maths/Vec2.h"

class Entity {
protected:
    Vec2 position;

public:
    virtual void draw() = 0;

    void setPos(const Vec2& pos);
    const Vec2& getPos();
};


#endif //PROJPROG2022_ENTITY_H
