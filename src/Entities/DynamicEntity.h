//
// Created by yami2200 on 19/05/22.
//

#ifndef PROJPROG2022_DYNAMICENTITY_H
#define PROJPROG2022_DYNAMICENTITY_H


#include "Entity.h"

class DynamicEntity : public Entity {

public:
    virtual void update() = 0;

};


#endif //PROJPROG2022_DYNAMICENTITY_H
