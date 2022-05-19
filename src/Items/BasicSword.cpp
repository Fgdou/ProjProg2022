//
// Created by yami2200 on 19/05/22.
//

#include "BasicSword.h"

BasicSword::BasicSword(Image sprite, double damage, double angle) : EquippableItem(sprite, damage), angle(angle){

}

void BasicSword::use(Player & player, std::vector<std::shared_ptr<DynamicEntity>> v_entities) {
    for(auto & entity : v_entities){
        if(std::abs(player.getPos().lookAt(entity->getPos()).angleBetween(player.getDirection())) < this->angle){
            try{
                auto dam = std::dynamic_pointer_cast<DamageableEntity>(entity);
                dam->takeDamage(player.getDamage() * this->damage);
            } catch(std::exception & e) {}
        }
    }
}
