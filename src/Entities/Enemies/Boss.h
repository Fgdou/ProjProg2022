//
// Created by guill on 20/05/2022.
//

#ifndef PROJPROG2022_BOSS_H
#define PROJPROG2022_BOSS_H

#include "BaseEnemy.h"

class Boss : public BaseEnemy {
protected:
    double distance;
    double distanceMax;
    bool isBump = false;
public:
    Boss(Vec2 & pos, double lifemax, double damage);

    void update(Room & room);
    void draw();

    double getDistance();

    void hasAttackedPlayer();
};


#endif //PROJPROG2022_BOSS_H
