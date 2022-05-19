//
// Created by guill on 19/05/2022.
//

#include "BaseEnemy.h"
#include "../Rooms/Room.h"

BaseEnemy::BaseEnemy(Vec2 & pos, double lifemax, double damage) : DamageableEntity(pos, lifemax), damage(damage){}

void BaseEnemy::update(Room & room) {
        auto player = room.getPlayer();
        Vec2 movement_vector = position.distance(player->getPos());
        Vec2 vec_move = movement_vector*speed ;
        auto c = room.getPlayerCollision(this->position, vec_move);
        if(c.isCollide()){
            this->setPos(c.getImpact());
            this->movement_vector = c.getRebound().normalize();
        } else {
            this->setPos(this->getPos() + this->movement_vector*speed);
            (this->movement_vector*speed).print();
        }
}

void BaseEnemy::draw() {

}

void BaseEnemy::dead() {

}
