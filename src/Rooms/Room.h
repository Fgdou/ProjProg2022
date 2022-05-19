//
// Created by fgdou on 5/19/22.
//

#ifndef PROJPROG2022_ROOM_H
#define PROJPROG2022_ROOM_H

#include "../Entities/Entity.h"
#include "../Entities/Player.h"
#include "Wall.h"
#include "Collision.h"
#include "../World.h"
#include <vector>
#include <cstdio>
#include "../Entities/DynamicEntity.h"

class DynamicEntity;

class Room
{
protected:
    std::vector<std::shared_ptr<DynamicEntity>> _entities;
    std::vector<std::shared_ptr<Wall>> _walls;
    std::vector<std::shared_ptr<Wall>> _doors;
    bool _isCleared;
    std::shared_ptr<World> _world;

public:
    Room(std::vector<std::shared_ptr<DynamicEntity>> entities, std::vector<std::shared_ptr<Wall>> walls, std::shared_ptr<World> world);

    void update();

    void draw();

    std::shared_ptr<Player> getPlayer() const;

    std::shared_ptr<World> getWorld() const;

    // Open the doors when the room is cleared
    void onClear();

    std::vector<std::shared_ptr<DynamicEntity>> getEntities();

    Collision getPlayerCollision(Vec2 currentPos, Vec2 directionToNextPos);
};

#endif // PROJPROG2022_ROOM_H
