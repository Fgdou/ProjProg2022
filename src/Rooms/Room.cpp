//
// Created by fgdou on 5/19/22.
//

#include <iostream>
#include "Room.h"
#include "../Entities/DynamicEntity.h"
#include "../World.h"

Room::Room(std::vector<std::shared_ptr<DynamicEntity>> entities, std::vector<std::shared_ptr<Wall>> walls, World &world) : _entities(entities), _walls(walls), _isCleared(false), _world(world)
{
}

void Room::update()
{
    auto it = _entities.begin();

    while (it != _entities.end())
    {
        auto dama = std::dynamic_pointer_cast<DamageableEntity>(*it);
        if (dama != nullptr && dama->isDead1())
        {
            it = _entities.erase(it);
            continue;
        }
        (*it)->update(*this);
        it++;
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

World &Room::getWorld() const
{
    return _world;
}

Collision Room::getCollisionAfterMove(Vec2 pos, Vec2 mov, unsigned int iter)
{
    // int iter = 0;
    // bool stillColliding = true;
    Collision col = {false};
    // while (stillColliding && iter < 2)
    // {
        for (std::shared_ptr<Wall> w : _walls)
        {
            Collision c = Collision::getLineRectCollision(
                pos,
                pos + mov,
                w->getPos(),
                w->getPos() + w->getSize());
            if (c.isColliding)
            {
                if (!col.isColliding || pos.distance(c.impact) < pos.distance(col.impact))
                    col = c;
            }
        }
    //     pos = col.impact + Vec2(0.0001) * col.newDir;
    //     mov = col.newDir;
        
    //     iter++;
    // }
    if (col.isColliding && iter < 10){
        Collision newCol = getCollisionAfterMove(col.impact + Vec2(0.001) * col.newDir, col.newDir, iter+1);
        if (newCol.isColliding)
            return newCol;
    }
    return col;
}

std::vector<std::shared_ptr<DynamicEntity>> Room::getEntities()
{
    return this->_entities;
}

void Room::updatePos(const Vec2 &pos)
{
    for (auto &e : _entities)
    {
        e->setPos(e->getPos() + pos);
    }
    for (auto &w : _walls)
    {
        w->setPos(w->getPos() + pos);
    }
    for (auto &w : _doors)
    {
        w->setPos(w->getPos() + pos);
    }
}
