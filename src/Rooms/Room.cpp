//
// Created by fgdou on 5/19/22.
//

#include "Room.h"
#include "../Entities/DynamicEntity.h"
#include "../World.h"

Room::Room(std::vector<std::shared_ptr<DynamicEntity>> entities, std::vector<std::shared_ptr<Wall>> walls, World & world) : _entities(entities), _walls(walls), _isCleared(false), _world(world)
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
        door->disable();
}

void Room::draw()
{
    for (auto &w : _walls)
        w->draw();
    for (auto &e : _entities)
        e->draw();
}

std::shared_ptr<Player> Room::getPlayer() const
{
    return _world.getPlayer();
}

World & Room::getWorld() const
{
    return _world;
}

Collision Room::getPlayerCollision(Vec2 pos, Vec2 mov)
{
    for (std::shared_ptr<Wall>& w : _walls)
    {
        Collision c = Collision::getLineRectCollision(
            pos,
            pos + mov,
            w->getPos(),
            w->getPos() + w->getSize());
        if (c.isCollide())
        {
            return {c.isCollide(), c.getImpact(), mov * c.getRebound()};
        }

    }
    return Collision(false, {}, {});
}

std::vector<std::shared_ptr<DynamicEntity>> Room::getEntities()
{
    return this->_entities;
}
