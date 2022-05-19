//
// Created by fgdou on 5/19/22.
//

#ifndef PROJPROG2022_ROOM_H
#define PROJPROG2022_ROOM_H

#include "../Entities/Entity.h"
#include "Wall.h"
#include "Collision.h"
#include <vector>

class DynamicEntity;

class Room
{
protected:
    std::vector<std::shared_ptr<DynamicEntity>> _entities;
    std::vector<std::shared_ptr<Wall>> _walls;
    std::vector<std::shared_ptr<Wall>> _doors;

public:
    Room(std::vector<std::shared_ptr<DynamicEntity>> entities, std::vector<std::shared_ptr<Wall>> walls);
    void update();
    void draw();

    Collision getPlayerCollision(Vec2 pos, Vec2 mov);
};

#endif // PROJPROG2022_ROOM_H
