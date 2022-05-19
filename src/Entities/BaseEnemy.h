//
// Created by guill on 19/05/2022.
//

#ifndef PROJPROG2022_ENEMY_H
#define PROJPROG2022_ENEMY_H

#include "DamageableEntity.h"
#include "Player.h"

class BaseEnemy : public DamageableEntity {
protected:
    double damage;
    double speed;
    Vec2 movement_vector;

public:
    BaseEnemy(Vec2 & pos, double lifemax, double damage);

    void update(Room & room) override;

    void draw() override;

protected:
    void dead() override;
};


#endif //PROJPROG2022_ENEMY_H
