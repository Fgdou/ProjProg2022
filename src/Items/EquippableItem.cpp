//
// Created by yami2200 on 19/05/22.
//

#include "EquippableItem.h"
#include "../Renderer.h"

EquippableItem::EquippableItem(Image sprite, double damage) : isEquipped(false), size(Vec2(1.0, 1.0)), sprite(sprite), angle(0.0), damage(damage) {

}

void EquippableItem::draw(Vec2 &pos) {
    Renderer::getInstance().drawImage(this->sprite, pos, this->size, this->angle);
}
