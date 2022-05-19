//
// Created by yami2200 on 19/05/22.
//

#include "SpinItem.h"
#include "../Maths/Timer.h"

void SpinItem::update() {
    if(this->current_cooldown > 0.0){
        this->current_cooldown -= Timer::getDeltaTime();
    }
    if(this->in_anim){
        this->current_angle += Timer::getDeltaTime()*this->angle*1000;
        if(this->cooldown_max - this->current_cooldown > this->duration){
            this->in_anim = false;
            this->current_angle = 0.0;
        }
    }
}

void SpinItem::draw(Vec2 &pos) {
    Renderer::getInstance().drawImage(this->sprite, pos, this->size, this->current_angle);
}

void SpinItem::use(Player &player, std::vector<std::shared_ptr<DynamicEntity>> v_entities) {
    if(this->current_cooldown <= 0.0){
        this->current_cooldown = this->cooldown_max;
        this->current_angle = 0;
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

SpinItem::SpinItem(Image sprite, Vec2 size, double cooldown, double damage, double length, double duration) : EquippableItem(sprite, size, cooldown+duration, damage), length(length), duration(duration) {

}
