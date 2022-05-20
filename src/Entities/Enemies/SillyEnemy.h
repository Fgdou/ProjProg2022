//
// Created by guill on 20/05/2022.
//

#ifndef PROJPROG2022_SILLYENEMY_H
#define PROJPROG2022_SILLYENEMY_H

#include "../BaseEnemy.h"


class SillyEnemy : public BaseEnemy {
public:
    void  update(Room & room);

    SillyEnemy(Vec2 & pos, double lifemax, double damage);
};


#endif //PROJPROG2022_SILLYENEMY_H
