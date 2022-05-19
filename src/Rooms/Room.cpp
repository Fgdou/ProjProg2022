//
// Created by fgdou on 5/19/22.
//

#include <cstdio>
#include "Room.h"
#include "../Entities/DynamicEntity.h"
#include "Door.h"

std::vector<std::shared_ptr<DynamicEntity>> entities;
std::vector<std::shared_ptr<Wall>> walls;
std::vector<std::shared_ptr<Door>> doors;

void update()
{
    if (entities.size() == 0)
    {
        for (auto i = doors.begin(); i != doors.end(); ++i)
        {
            if (!(*i)->keyNeeded())
                i = doors.erase(i);
        }
    }
    for (int i = 0; i < entities.size(); ++i)
    {
        entities[i]->update();
    }
}
void draw();

Collision Room::getPlayerCollision(Vec2 pos, Vec2 mov)
{
}
