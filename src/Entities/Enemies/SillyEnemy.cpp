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
    auto player = room.getPlayer();
    Vec2 vec_move = movement_vector*speed*Timer::getDeltaTime();
    if(this->isBump){
        this->setPos(this->getPos() + this->movement_vector*(this->speedBump*15));
        this->speedBump -= Timer::getDeltaTime();
        if(this->speedBump <= 0.0) this->isBump = false;
    } else {
        this->movement_vector = position.lookAt(player->getPos()).rotate(this->current_angle).normalize();
        this->setPos(this->getPos() + this->movement_vector*speed);
    }

    if (this->forward) {
        this->current_angle += 3 * Timer::getDeltaTime();
        if (this->current_angle > this->angle) {
            this->forward = false;
        }
    } else {
        this->current_angle -= 3 * Timer::getDeltaTime();
        if (this->current_angle < -this->angle) {
            this->forward = true;
        }
    }

}

SillyEnemy::SillyEnemy(Vec2 &pos, double lifemax, double damage) : BaseEnemy(pos, lifemax, damage) , angle(0.6), current_angle(0.6), forward(false){
    this->movement_vector = Vec2(1, 1);
    this->speed = 5;
}


void SillyEnemy::draw() {
    double rota = Vec2::toDegrees(this->movement_vector.angle())-90;
    if(this->timerHitDamage > 0.0){
        //Renderer::getInstance().drawCircle(this->getPos(), 20.0, {255, 0, 0, 255});
        Renderer::getInstance().drawImage({"../assets/enemy2_hurt.png"}, this->getPos(), Vec2(60.0, 60.0), rota);
        Renderer::getInstance().drawText(std::to_string(this->lastDamage), this->getPos()+Vec2(0.0, -30-70.0*this->timerHitDamage*2), 30, {255, 0, 0, 255});
    } else {
        //Renderer::getInstance().drawCircle(this->getPos(), 20.0, {0, 255, 0, 255});
        Renderer::getInstance().drawImage({"../assets/enemy2.png"}, this->getPos(), Vec2(60.0, 60.0), rota);
    }
}
