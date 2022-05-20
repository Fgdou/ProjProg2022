//
// Created by guill on 19/05/2022.
//

#include <iostream>
#include "BaseEnemy.h"
#include "../Rooms/Room.h"
#include "../Maths/Timer.h"

BaseEnemy::BaseEnemy(Vec2 & pos, double lifemax, double damage)
    : DamageableEntity(pos, lifemax), damage(damage), speed(2.0), lastDamage(0), cooldownDamage(0.0), timerHitDamage(0.0){}

void BaseEnemy::update(Room & room) {
        if(this->timerHitDamage > 0.0) this->timerHitDamage -= Timer::getDeltaTime();
        if(this->cooldownDamage > 0.0) this->cooldownDamage -= Timer::getDeltaTime();
        auto player = room.getPlayer();
        if(this->isBump){
            this->setPos(this->getPos() + this->movement_vector*(this->speedBump*15));
            this->speedBump -= Timer::getDeltaTime();
            if(this->speedBump <= 0.0) this->isBump = false;
        } else {
            this->movement_vector = position.lookAt(player->getPos()).normalize();
            Vec2 vec_move = movement_vector*speed*Timer::getDeltaTime();
            this->setPos(this->getPos() + this->movement_vector*speed);
        }

}

void BaseEnemy::draw() {
    if(this->timerHitDamage > 0.0){
        Renderer::getInstance().drawCircle(this->getPos(), 20.0, {255, 0, 0, 255});
        Renderer::getInstance().drawText(std::to_string(this->lastDamage), this->getPos()+Vec2(0.0, -30-70.0*this->timerHitDamage*2), 30, {255, 0, 0, 255});
    } else {
        Renderer::getInstance().drawCircle(this->getPos(), 20.0, {0, 255, 0, 255});
    }
}

void BaseEnemy::takeDamage(double damage) {
    if(this->timerHitDamage <= 0.0){
        DamageableEntity::takeDamage(damage);
        this->timerHitDamage = 0.4;
        this->lastDamage = damage;
    }
}

double BaseEnemy::getDamage() {
    return this->damage;
}

void BaseEnemy::hasAttackedPlayer() {
    this->cooldownDamage = 0.5;
}

bool BaseEnemy::canAttack() {
    return this->cooldownDamage <= 0.0 && !this->isBump;
}

void BaseEnemy::bump(Vec2 dir) {
    if(!this->isBump){
        this->isBump = true;
        this->movement_vector = dir.normalize();
        this->speedBump = 0.5;
    }
}
