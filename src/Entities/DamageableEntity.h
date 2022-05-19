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
    bool isDead;

    virtual void dead();
public:
    DamageableEntity(Vec2 & pos, double lifemax);

    virtual void takeDamage(double damage);

    double getLifeMax() const;

    double getLife() const;

    bool isDead1() const;

    void heal(double life_amount);
};


#endif //PROJPROG2022_DAMAGEABLEENTITY_H
