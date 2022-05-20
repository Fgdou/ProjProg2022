//
// Created by guill on 19/05/2022.
//

#ifndef PROJPROG2022_ENEMY_H
#define PROJPROG2022_ENEMY_H

#include "DamageableEntity.h"
#include "Player.h"

class BaseEnemy : public DamageableEntity {
protected:
public:
    void takeDamage(double damage) override;

protected:
    double damage;
    double speed;
    Vec2 movement_vector;
    double timerHitDamage;
    double cooldownDamage;
    int lastDamage;

public:
    BaseEnemy(Vec2 & pos, double lifemax, double damage);

    void update(Room & room) override;

    void draw() override;

    double getDamage();

    void hasAttackedPlayer();

    bool canAttack();

    void bump(Vec2 dir) override;
};


#endif //PROJPROG2022_ENEMY_H
