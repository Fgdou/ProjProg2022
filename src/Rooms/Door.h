//
// Created by guill on 19/05/2022.
//

#ifndef PROJPROG2022_DOOR_H
#define PROJPROG2022_DOOR_H


#include "../Entities/Entity.h"
#include "Wall.h"

class Door : public Wall{
protected:
    bool needKey=0;
public:
    bool keyNeeded();
};


#endif //PROJPROG2022_DOOR_H
