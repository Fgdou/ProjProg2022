//
// Created by fgdou on 5/19/22.
//

#include <iostream>
#include "Room.h"
#include "../Entities/DynamicEntity.h"
#include "../World.h"
#include "../Entities/Blood.h"
#include "../Theme.h"

Room::Room(std::vector<std::shared_ptr<DynamicEntity>> entities, std::vector<std::shared_ptr<Wall>> walls, World &world) : _entities(entities), _walls(walls), _blood(std::vector<std::shared_ptr<Blood>>()), _isCleared(false), _world(world)
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
            for(int i = 0; i < 50; i++){
                int min = 2;
                int max = 35;
                double speed = min + (rand() % static_cast<int>(max*3 - min + 1));
                double size = min*2 + (rand() % static_cast<int>(max/3 - min*2 + 1));
                double randAngle = -1.2 + ((double)rand() / RAND_MAX) * (1.2 + 1.2);
                double life = 0.7 + ((double)rand() / RAND_MAX) * (1.6 - 0.7);
                Vec2 dir =it->get()->getPos()+it->get()->getPos().lookAt(getPlayer()->getPos()).rotate(randAngle).normalize()*(-speed);
                _blood.push_back(std::make_shared<Blood>(it->get()->getPos(), dir, size, life));
            }
            it = _entities.erase(it);
            continue;
        }
        (*it)->update(*this);
        it++;
    }

    auto it2 = _blood.begin();
    while (it2 != _blood.end())
    {
        if (it2->get() != nullptr && it2->get()->isDead1())
        {
            it2 = _blood.erase(it2);
            continue;
        }
        (*it2)->update(*this);
        it2++;
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

    for (auto &w : _walls){
        SDL_Color wallColor = Theme::wall;
        if (Renderer::getInstance().funMeter < 0)
        {
            wallColor.r = Theme::wall.r * (1 + (Renderer::getInstance().funMeter / 100)) + Theme::wall_low.r * (- Renderer::getInstance().funMeter / 100);
            wallColor.g = Theme::wall.g * (1 + (Renderer::getInstance().funMeter / 100)) + Theme::wall_low.g * (- Renderer::getInstance().funMeter / 100);
            wallColor.b = Theme::wall.b * (1 + (Renderer::getInstance().funMeter / 100)) + Theme::wall_low.b * (- Renderer::getInstance().funMeter / 100);
        }
        else if (Renderer::getInstance().funMeter > 0)
        {
            wallColor.r = Theme::wall.r * (1 - (Renderer::getInstance().funMeter / 100)) + Theme::wall_high.r * (Renderer::getInstance().funMeter / 100);
            wallColor.g = Theme::wall.g * (1 - (Renderer::getInstance().funMeter / 100)) + Theme::wall_high.g * (Renderer::getInstance().funMeter / 100);
            wallColor.b = Theme::wall.b * (1 - (Renderer::getInstance().funMeter / 100)) + Theme::wall_high.b * (Renderer::getInstance().funMeter / 100);
        }
        w->setColor(wallColor);
    }
}

void Room::onClear()
{
    for (auto &door : _doors)
        door->disable();
}

void Room::draw()
{
    for (auto &e : _blood)
        e->draw();
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
