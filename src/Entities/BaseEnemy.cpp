//
// Created by guill on 19/05/2022.
//

#include <iostream>
#include "BaseEnemy.h"
#include "../Rooms/Room.h"
#include "../Maths/Timer.h"

BaseEnemy::BaseEnemy(Vec2 & pos, double lifemax, double damage)
    : DamageableEntity(pos, lifemax), damage(damage), speed(2.0){}

void BaseEnemy::update(Room & room) {
        if(this->timerHitDamage > 0.0) this->timerHitDamage -= Timer::getDeltaTime();
        if(this->cooldownDamage > 0.0) this->cooldownDamage -= Timer::getDeltaTime();
        auto player = room.getPlayer();
        this->movement_vector = position.lookAt(player->getPos()).normalize();
        Vec2 vec_move = movement_vector*speed*Timer::getDeltaTime() ;
        /*auto c = room.getCollisionAfterMove(this->position, vec_move);
        if(c.isColliding){
            this->setPos(c.newPos);
            this->movement_vector = c.newDir.normalize();
        } else {*/
            this->setPos(this->getPos() + this->movement_vector*speed);
        //}
}

void BaseEnemy::draw() {
    if(this->timerHitDamage > 0.0){
        Renderer::getInstance().drawCircle(this->getPos(), 20.0, {255, 0, 0, 255});
    } else {
        Renderer::getInstance().drawCircle(this->getPos(), 20.0, {0, 255, 0, 255});
    }
}

void BaseEnemy::takeDamage(double damage) {
    if(this->timerHitDamage <= 0.0){
        DamageableEntity::takeDamage(damage);
        this->timerHitDamage = 0.4;
    }
}

double BaseEnemy::getDamage() {
    return this->damage;
}

void BaseEnemy::hasAttackedPlayer() {
    this->cooldownDamage = 0.5;
}

bool BaseEnemy::canAttack() {
    return this->cooldownDamage <= 0.0;
}
