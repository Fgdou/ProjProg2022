//
// Created by yami2200 on 19/05/22.
//

#include <iostream>
#include "BasicSword.h"
#include "../Maths/Timer.h"

BasicSword::BasicSword(Image sprite, Vec2 size, double cooldown, double damage, double angle, double length) : EquippableItem(sprite, size, cooldown, damage), angle(angle), length(length), in_anim(false), current_angle(0){

}

void BasicSword::use(Player & player, std::vector<std::shared_ptr<DynamicEntity>> v_entities) {
    if(this->current_cooldown <= 0.0){
        this->current_cooldown = this->cooldown_max;
        this->current_angle = -this->angle;
        this->in_anim = true;
        for(auto & entity : v_entities){
            if(std::abs(player.getPos().lookAt(entity->getPos()).angleBetween(player.getDirection())) < this->angle){
                if (auto * de = dynamic_cast<DamageableEntity*>(entity.get()))
                {
                    de->takeDamage(player.getDamage() * this->damage);
                }
            }
        }
    }
}

void BasicSword::draw(Vec2 &pos) {
    auto mouse = Input::getInstance().getMousePos();
    if(!this->in_anim){
        this->relative_position = pos.lookAt(mouse).normalize()*15;
        this->relative_rotation = Vec2::toDegrees(Vec2(0.0, -1.0).angleBetween(pos.lookAt(mouse)));
    }
    Renderer::getInstance().drawImage(this->sprite, pos + this->relative_position, this->size, this->relative_rotation+this->current_angle);
}

void BasicSword::update(Player &player, std::vector<std::shared_ptr<DynamicEntity>> v_entities) {
    if(this->current_cooldown > 0.0){
        this->current_cooldown -= Timer::getDeltaTime();
    }
    if(this->in_anim){
        this->current_angle += Timer::getDeltaTime()*this->angle*15;
        if(this->current_angle>this->angle){
            this->in_anim = false;
            this->current_angle = 0.0;
        }
    }
}