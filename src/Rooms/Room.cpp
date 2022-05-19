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
}
void draw(){

}

Collision Room::getPlayerCollision(Vec2 pos, Vec2 mov){

}
