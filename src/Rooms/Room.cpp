//
// Created by fgdou on 5/19/22.
//

#include <cstdio>
#include "Room.h"
#include "../Entities/DynamicEntity.h"
#include "Door.h"

std::vector<std::shared_ptr<DynamicEntity>> entities;
std::vector<std::shared_ptr<Wall>> walls;

Room::Room(std::vector<std::shared_ptr<DynamicEntity>> entities, std::vector<std::shared_ptr<Wall>> walls): entities(entities), walls(walls) {

}

void update()
{
    if(entities.size()==1){
        for (std::shared_ptr<Wall> w: walls) {
            w->open();
        }
    }
    else{
        for(std::shared_ptr<DynamicEntity>e : entities){
            //e->update(this);
        }
    }
}
void draw(){
    for (std::shared_ptr<Wall> w: walls) {
        w->draw();
    }
    for(std::shared_ptr<DynamicEntity>e : entities){
        e->draw();
    }
}

Collision Room::getPlayerCollision(Vec2 pos, Vec2 mov){
    return Collision(false, {}, {});
}
