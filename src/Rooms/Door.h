//
// Created by guill on 19/05/2022.
//

#ifndef PROJPROG2022_DOOR_H
#define PROJPROG2022_DOOR_H


#include "Wall.h"

class Door : public Wall{
protected:
    bool closed;

public:
    Door(Vec2 pos = (0,0), Vec2 size = (0,0), bool closed=1);
    void open() override;
    void draw() override;
};


#endif //PROJPROG2022_DOOR_H
