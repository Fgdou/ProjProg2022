//
// Created by yami2200 on 19/05/22.
//

#include "DamageableEntity.h"

DamageableEntity::DamageableEntity(Vec2 &pos, double lifemax) : DynamicEntity(pos), life_max(lifemax), life(lifemax){

}

void DamageableEntity::takeDamage(double damage) {
    this->life -= damage;
    if(this->life <= 0.0) this->dead();
}

void DamageableEntity::heal(double life_amount) {
    this->life += life_amount;
    if(this->life_max < this->life) this->life = this->life_max;
}
