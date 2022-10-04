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
    bool inAttack;
    double jump;
    bool inJump;
    bool forwardJump;
    double speedJump;
    bool dealDamage;

    Image imageBoss;
    Image imageBossHurt;
    Image imageBossAoe;

public:
    Boss(Vec2 & pos, double lifemax, double damage);

    void update(Room & room);
    void draw();

    double getDistance();

    void hasAttackedPlayer() override;

    bool canDealDamage();

    void dealsDamage();

    double getPercentLife();

    void printLife();
};


#endif //PROJPROG2022_BOSS_H
