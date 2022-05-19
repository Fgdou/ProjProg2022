//
// Created by fgdou on 5/19/22.
//

#include <cstdio>
#include "Room.h"
#include "../Entities/DynamicEntity.h"

Room::Room(std::vector<std::shared_ptr<DynamicEntity>> entities, std::vector<std::shared_ptr<Wall>> walls) : _entities(entities), _walls(walls), _isCleared(false)
{
}

void Room::update()
{
    for (auto &entity : _entities)
    {
        entity->update(*this);
    }

    // check if the room is cleared
    if (!_isCleared)
    {
        if (_entities.size() == 1)
        {
            _isCleared = true;
            onClear();
        }
    }
}

void Room::onClear()
{
    for (auto &door : _doors)
    {
        door->disable();
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
    for (std::shared_ptr<Wall> w : _walls)
    {
        Collision c = Collision::getLineRectCollision(
            w->getPos(),
            w->getPos() + w->getSize(), );
        if (c.isCollide())
        {
            return Collision(c.isCollide(), c.getImpact(), mov * c.getRebound());
        }
    }
    return Collision(false, {}, {});
}
