//
// Created by yami2200 on 20/05/22.
//

#include "Blood.h"
#include "../Renderer.h"
#include "../Maths/Timer.h"

Blood::Blood(Vec2 pos, Vec2 dir, double size, double life) : DamageableEntity(pos, life), dir_point(dir), size(size){

}

void Blood::takeDamage(double damage) {
    return;
}

void Blood::update(Room &room) {
    if(this->getPos().distance(this->dir_point) > 8){
        this->setPos(this->getPos()+this->getPos().lookAt(this->dir_point).normalize() * 10);
    }
    this->life = this->life - Timer::getDeltaTime();
    if(this->life <= 0.0 && !this->isDead) this->dead();
}

void Blood::draw() {
    Renderer::getInstance().drawCircle(this->getPos(), this->size, {255, 0, 0 , static_cast<Uint8>(((std::abs(life/life_max))*255.0))});
}