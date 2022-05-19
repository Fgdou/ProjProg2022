//
// Created by fgdou on 5/19/22.
//

#include <cstdio>
#include "Room.h"
#include "../Entities/DynamicEntity.h"

Room::Room(std::vector<std::shared_ptr<DynamicEntity>> entities, std::vector<std::shared_ptr<Wall>> walls) : _entities(entities), _walls(walls)
{
}

void Room::update()
{
    if (_entities.size() == 1)
    {
        for (std::shared_ptr<Wall> w : _walls)
        {
            w->open();
        }
    }
    else
    {
        for (std::shared_ptr<DynamicEntity> e : _entities)
        {
            // e->update(this);
        }
    }
}

void Room::draw()
{
    for (std::shared_ptr<Wall> w : _walls)
    {
        w->draw();
    }
    for (std::shared_ptr<DynamicEntity> e : _entities)
    {
        e->draw();
    }
}

Collision Room::getPlayerCollision(Vec2 pos, Vec2 mov)
{
    return Collision(false, {}, {});
}
