//
// Created by yami2200 on 19/05/22.
//

#include <iostream>
#include "SpinItem.h"
#include "../Maths/Timer.h"

SpinItem::SpinItem(Image sprite, Image spin_sprite, Vec2 size, Vec2 spin_size, double cooldown, double damage, double length, double duration) : EquippableItem(sprite, size, cooldown+duration, damage), spin_sprite(spin_sprite) , in_anim(false), length(length), duration(duration), lastPos() , pos(), spin_size(spin_size)
{}


void SpinItem::update(Player &player, const std::vector<std::shared_ptr<DynamicEntity>>& v_entities) {
    if(this->current_cooldown > 0.0){
        this->current_cooldown -= Timer::getDeltaTime();
    }
    if(this->in_anim){
        for(auto & entity : v_entities){
            if(entity->getPos().distance(player.getPos())< this->length){
                if (auto * de = dynamic_cast<DamageableEntity*>(entity.get()))
                {
                    de->takeDamage(player.getDamage() * this->damage);
                    de->bump(player.getPos().lookAt(de->getPos()).normalize());
                }
            }
        }

        this->current_angle += Timer::getDeltaTime()*this->angle*2000;
        if(this->cooldown_max - this->current_cooldown > this->duration){
            this->in_anim = false;
            this->current_angle = 0.0;
        }
    }
    this->lastPos = this->pos;
    this->pos = player.getPos();
}

void SpinItem::draw(Vec2 &pos) {
    if(this->in_anim){
        Renderer::getInstance().drawImage(this->spin_sprite, pos, this->spin_size * Vec2(5), this->current_angle);
    } else {
        double offset = 10;
        Vec2 backward = (this->lastPos - this->pos);
        double length = backward.norm();
        backward = backward.normalize()*std::min(length, 10.0);
        Renderer::getInstance().drawImage(this->sprite, pos + backward * Vec2(offset), this->size* Vec2(6), Vec2::toDegrees(backward.angle())+90);
    }

}

void SpinItem::use(Player &player, const std::vector<std::shared_ptr<DynamicEntity>>& v_entities) {
    EquippableItem::use(player, v_entities);
    if(this->current_cooldown <= 0.0){
        this->current_cooldown = this->cooldown_max;
        this->current_angle = 0;
        this->in_anim = true;
    }
}

