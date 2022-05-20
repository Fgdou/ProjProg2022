//
// Created by guill on 20/05/2022.
//

#include "Boss.h"
#include "../../Maths/Timer.h"

Boss::Boss(Vec2 & pos, double lifemax, double damage): BaseEnemy(pos, lifemax, damage), distance(0.0), distanceMax(0.4){}

double Boss::getDistance() {
    return distance;
}

void Boss::update(Room & room){
    if(this->cooldownDamage > 0.0){
        this->cooldownDamage -= Timer::getDeltaTime();
    } else if(distance < distanceMax){
        distance += 0.05;
    } else{
        distance = 0;
        this->hasAttackedPlayer();
    }

    if(this->timerHitDamage > 0.0){
        this->timerHitDamage -= Timer::getDeltaTime();
        Renderer::getInstance().drawCircle(this->getPos(), 20.0, {255, 0, 0, 255});
        Renderer::getInstance().drawText(std::to_string(this->lastDamage), this->getPos()+Vec2(0.0, -30-70.0*this->timerHitDamage*2), 30, {255, 0, 0, 255});
    } else {
        Renderer::getInstance().drawCircle(this->getPos(), 20.0, {0, 255, 0, 255});
    }
}

void Boss::draw() {
    if(this->timerHitDamage > 0.0){
        Renderer::getInstance().drawCircle(this->getPos(), 20.0, {255, 0, 0, 255});
        Renderer::getInstance().drawText(std::to_string(this->lastDamage), this->getPos()+Vec2(0.0, -30-70.0*this->timerHitDamage*2), 30, {255, 0, 0, 255});
    } else {
        Renderer::getInstance().drawCircle(this->getPos(), 20.0, {0, 255, 0, 255});
    }

}

void Boss::hasAttackedPlayer() {
    this->cooldownDamage = 1.5;
}