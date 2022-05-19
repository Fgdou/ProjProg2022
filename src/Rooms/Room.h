//
// Created by fgdou on 5/19/22.
//

#ifndef PROJPROG2022_ROOM_H
#define PROJPROG2022_ROOM_H

#include "Wall.h"
#include "Collision.h"
#include <vector>
#include <cstdio>

class World;
class Player;
class DynamicEntity;

class Room
{
protected:
    std::vector<std::shared_ptr<DynamicEntity>> _entities;
    std::vector<std::shared_ptr<Wall>> _walls;
    std::vector<std::shared_ptr<Wall>> _doors;
    bool _isCleared;
    World & _world;

public:
    Room(std::vector<std::shared_ptr<DynamicEntity>> entities, std::vector<std::shared_ptr<Wall>> walls, World & world);

    void update();

    void draw();

    std::shared_ptr<Player> getPlayer() const;

    World & getWorld() const;

    // Open the doors when the room is cleared
    void onClear();

    std::vector<std::shared_ptr<DynamicEntity>> getEntities();

    Collision getPlayerCollision(Vec2 currentPos, Vec2 directionToNextPos);
};

#endif // PROJPROG2022_ROOM_H
