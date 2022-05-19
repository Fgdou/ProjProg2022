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
    void open() override;
    void draw() override;
};


#endif //PROJPROG2022_DOOR_H
