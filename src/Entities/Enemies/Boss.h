//
// Created by guill on 20/05/2022.
//

#ifndef PROJPROG2022_BOSS_H
#define PROJPROG2022_BOSS_H

#include "BaseEnemy.h"

class Boss : public BaseEnemy {
public:
    Boss(Vec2 & pos, double lifemax, double damage);
};


#endif //PROJPROG2022_BOSS_H
