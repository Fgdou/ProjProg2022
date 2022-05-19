//
// Created by guill on 19/05/2022.
//

#ifndef PROJPROG2022_WALL_H
#define PROJPROG2022_WALL_H


#include "../Entities/Entity.h"

class Wall : public Entity {
protected:
    Vec2 size;

public:
    void draw();


};


#endif //PROJPROG2022_WALL_H
