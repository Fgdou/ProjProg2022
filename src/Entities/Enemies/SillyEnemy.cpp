//
// Created by guill on 20/05/2022.
//

#include <iostream>
#include "SillyEnemy.h"
#include "../../Rooms/Room.h"
#include "../../Maths/Timer.h"

void SillyEnemy::update(Room & room) {
    if(this->timerHitDamage > 0.0) this->timerHitDamage -= Timer::getDeltaTime();
    if(this->cooldownDamage > 0.0) this->cooldownDamage -= Timer::getDeltaTime();
    Vec2 vec_move = movement_vector*speed*Timer::getDeltaTime() ;
    auto c = room.getCollisionAfterMove(this->getPos(), vec_move);
    if(c.isColliding){
        this->setPos(c.newPos);
        this->movement_vector = c.newDir.normalize();
        double randAngle = -1.2 + ((double)rand() / RAND_MAX) * (1.2 + 1.2);
        movement_vector.rotate(randAngle);
    } else {
        this->setPos(this->getPos() + this->movement_vector*speed);
    }
}

SillyEnemy::SillyEnemy(Vec2 &pos, double lifemax, double damage) : BaseEnemy(pos, lifemax, damage) {
    this->movement_vector = Vec2(1, 1);
    this->speed = 5;
}
