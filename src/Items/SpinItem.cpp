//
// Created by yami2200 on 19/05/22.
//

#include "SpinItem.h"
#include "../Maths/Timer.h"

void SpinItem::update(Player &player, std::vector<std::shared_ptr<DynamicEntity>> v_entities) {
    if(this->current_cooldown > 0.0){
        this->current_cooldown -= Timer::getDeltaTime();
    }
    if(this->in_anim){
        for(auto & entity : v_entities){
            if(entity->getPos().distance(player.getPos())< this->length){
                if (auto * de = dynamic_cast<DamageableEntity*>(entity.get()))
                {
                    de->takeDamage(player.getDamage() * this->damage);
                }
            }
        }

        this->current_angle += Timer::getDeltaTime()*this->angle*1000;
        if(this->cooldown_max - this->current_cooldown > this->duration){
            this->in_anim = false;
            this->current_angle = 0.0;
        }
    }
}

void SpinItem::draw(Vec2 &pos) {
    if(this->in_anim){
        Renderer::getInstance().drawImage(this->sprite, pos, this->size, this->current_angle);
    } else {
        Renderer::getInstance().drawImage(this->sprite, pos, this->size*Vec2(1.0,0.3), this->current_angle);
    }

}

void SpinItem::use(Player &player, std::vector<std::shared_ptr<DynamicEntity>> v_entities) {
    if(this->current_cooldown <= 0.0){
        this->current_cooldown = this->cooldown_max;
        this->current_angle = 0;
        this->in_anim = true;
    }
}

SpinItem::SpinItem(Image sprite, Vec2 size, double cooldown, double damage, double length, double duration) : EquippableItem(sprite, size, cooldown+duration, damage), length(length), duration(duration) {

}
