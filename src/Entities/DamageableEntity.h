//
// Created by yami2200 on 19/05/22.
//

#ifndef PROJPROG2022_DAMAGEABLEENTITY_H
#define PROJPROG2022_DAMAGEABLEENTITY_H


#include "DynamicEntity.h"

class DamageableEntity : public DynamicEntity{
protected:
    double life_max;
    double life;

    virtual void dead() = 0;
public:
    DamageableEntity(Vec2 & pos, double lifemax);

    void takeDamage(double damage);

    void heal(double life_amount);
};


#endif //PROJPROG2022_DAMAGEABLEENTITY_H
