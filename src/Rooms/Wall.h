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
//    void draw() override;

    virtual void open() = 0;


};


#endif //PROJPROG2022_WALL_H
