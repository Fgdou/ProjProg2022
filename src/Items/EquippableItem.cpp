//
// Created by yami2200 on 19/05/22.
//

#include "EquippableItem.h"
#include "../Renderer.h"
#include "../Maths/Timer.h"
#include "../Entities/DynamicEntity.h"

EquippableItem::EquippableItem(Image sprite, Vec2 size, double cooldown, double damage) : isEquipped(false), size(size), sprite(sprite), angle(1.0), damage(damage), cooldown_max(cooldown) {

}

void EquippableItem::draw(Vec2 &pos) {
    Renderer::getInstance().drawImage(this->sprite, pos, this->size, this->angle);
}

void EquippableItem::use(Player &player, const std::vector<std::shared_ptr<DynamicEntity>>& v_entities) {

}

void EquippableItem::update(Player &player, const std::vector<std::shared_ptr<DynamicEntity>>& v_entities) {
    if(this->current_cooldown > 0.0){
        this->current_cooldown -= Timer::getDeltaTime();
    }
}
