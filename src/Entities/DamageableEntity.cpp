//
// Created by yami2200 on 19/05/22.
//

#include "DamageableEntity.h"

DamageableEntity::DamageableEntity(Vec2 &pos, double lifemax) : DynamicEntity(pos), life_max(lifemax), life(lifemax), isDead(false){

}

void DamageableEntity::takeDamage(double damage) {
    this->life -= damage;
    if(this->life <= 0.0) this->dead();
}

void DamageableEntity::heal(double life_amount) {
    this->life += life_amount;
    if(this->life_max < this->life) this->life = this->life_max;
}

void DamageableEntity::dead() {
    this->isDead = true;
}

bool DamageableEntity::isDead1() const {
    return isDead;
}

double DamageableEntity::getLifeMax() const {
    return life_max;
}

double DamageableEntity::getLife() const {
    return life;
}

void DamageableEntity::bump(Vec2 dir) {

}

bool DamageableEntity::getIsBump() {
    return this->isBump;
}
