//
// Created by yami2200 on 19/05/22.
//

#include "EquippableItem.h"
#include "../Renderer.h"
#include "../Maths/Timer.h"
#include "../Entities/DynamicEntity.h"
#include "../Theme.h"

EquippableItem::EquippableItem(Image sprite, Vec2 size, double cooldown, double damage) : isEquipped(false), size(size), sprite(sprite), angle(1.0), damage(damage), current_cooldown(0.0), cooldown_max(cooldown) {

}

void EquippableItem::draw(Vec2 &pos) {
    Renderer::getInstance().drawImage(this->sprite, pos, this->size, this->angle);
    printProgressBar(pos);
}

void EquippableItem::use(Player &player, const std::vector<std::shared_ptr<DynamicEntity>>& v_entities) {

}

void EquippableItem::update(Player &player, const std::vector<std::shared_ptr<DynamicEntity>>& v_entities) {
    if(this->current_cooldown > 0.0){
        this->current_cooldown -= Timer::getDeltaTime();
    }
}

double EquippableItem::getPercentCooldown() const {
    return current_cooldown/cooldown_max;
}

void EquippableItem::printProgressBar(const Vec2 &pos) {
    double p = getPercentCooldown();
    if(p <= 0 || p >= 1)
        return;

    Vec2 ssize{
        50,
        7
    };
    auto newSize = ssize;
    newSize.x *= p;
    auto newpose = pos + Vec2{0, 30};
    newpose.x -= ssize.x/2*(1-p);

    Renderer::getInstance().drawRect(newpose, newSize, Theme::progressCooldown);
}
