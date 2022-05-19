//
// Created by fgdou on 5/19/22.
//

#include "Chest.h"

#include <utility>
#include "../Rooms/Room.h"
#include "../Items/EquippableItem.h"
#include "../Rooms/Collision.h"

Chest::Chest(Vec2 &pos, Vec2& size, std::shared_ptr<EquippableItem> item)
    : DynamicEntity(pos), item(std::move(item)), t_close("../assets/chest_close.png"), t_open("../assets/chest_open.png"), size(size)
{

}

void Chest::draw() {
    if(item == nullptr){
        Renderer::getInstance().drawImage(t_open, getPos(), size, 0);
    }else{
        Renderer::getInstance().drawImage(t_close, getPos(), size, 0);
    }
}

void Chest::update(Room &room) {
    //TODO interact with player
//    Collision::getPointInsideRectCollision(room)
}
