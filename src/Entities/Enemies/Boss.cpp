//
// Created by guill on 20/05/2022.
//

#include "Boss.h"
#include "../../Maths/Timer.h"

Boss::Boss(Vec2 & pos, double lifemax, double damage): BaseEnemy(pos, lifemax, damage), distance(0.0), distanceMax(350), inAttack(false), jump(0.0), inJump(false), speedJump(0.0), dealDamage(false){

}

double Boss::getDistance() {
    return distance;
}

void Boss::update(Room & room){
    if(this->timerHitDamage > 0.0) this->timerHitDamage -= Timer::getDeltaTime();
    if(this->cooldownDamage > 0.0) this->cooldownDamage -= Timer::getDeltaTime();
    if(this->cooldownDamage <= 0.0){
        this->inAttack = true;
        this->forwardJump = true;
        this->inJump = true;
        this->hasAttackedPlayer();
        this->distance = 0.0;
        this->speedJump = 500.0;
        this->dealDamage = false;
    } else {
        if(this->inAttack){
            if(this->inJump){
                if(this->forwardJump){
                    this->speedJump -= Timer::getDeltaTime()*1300;
                    this->jump += this->speedJump*Timer::getDeltaTime();
                    if(this->speedJump <= 0.0) this->forwardJump = false;
                } else {
                    this->speedJump += Timer::getDeltaTime()*1300;
                    this->jump -= this->speedJump*Timer::getDeltaTime();
                    if(this->jump <= 0.0) this->inJump = false;
                }
            } else {
                this->distance += Timer::getDeltaTime()*800;
                if(this->distanceMax < this->distance){
                    this->inAttack = false;
                    this->dealDamage = false;
                    this->distance = 0.0;
                }
            }
        }
    }
}

void Boss::draw() {
    if(this->inAttack){
        Renderer::getInstance().drawImage({"../assets/boss_aoe.png"}, this->getPos(), Vec2(1.0,1.0)*(this->distance*2.5), 0.0);
    }
    if(this->timerHitDamage > 0.0){
        Renderer::getInstance().drawText(std::to_string(this->lastDamage), this->getPos()+Vec2(0.0, -80-70.0*this->timerHitDamage*2), 50, {255, 0, 0, 255});
        Renderer::getInstance().drawImage({"../assets/boss_hurt.png"}, this->getPos()+Vec2(0.0, -this->jump), Vec2(200.0, 200.0), 0.0);
    } else {
        Renderer::getInstance().drawImage({"../assets/boss.png"}, this->getPos()+Vec2(0.0, -this->jump), Vec2(200.0, 200.0), 0.0);
    }
}

void Boss::hasAttackedPlayer() {
    this->cooldownDamage = 3.3;
}

bool Boss::canDealDamage() {
    return !this->dealDamage;
}

void Boss::dealsDamage() {
    this->dealDamage = true;
}
