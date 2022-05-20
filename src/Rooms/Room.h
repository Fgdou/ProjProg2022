//
// Created by fgdou on 5/19/22.
//

#ifndef PROJPROG2022_ROOM_H
#define PROJPROG2022_ROOM_H

#include "Wall.h"
#include "Collision.h"
#include "../Entities/Blood.h"
#include <vector>
#include <cstdio>

class World;
class Player;
class DynamicEntity;

class Room
{
protected:
    std::vector<std::shared_ptr<DynamicEntity>> _entities;
    std::vector<std::shared_ptr<Blood>> _blood;
    std::vector<std::shared_ptr<Wall>> _walls;
    std::vector<std::shared_ptr<Wall>> _doors;
    bool _isCleared;
    World & _world;

    int cntMonsters();

public:
    Room(std::vector<std::shared_ptr<DynamicEntity>> entities, std::vector<std::shared_ptr<Wall>> doors , std::vector<std::shared_ptr<Wall>> walls, World & world);

    void update();

    void draw();

    std::shared_ptr<Player> getPlayer() const;

    World & getWorld() const;

    // Open the doors when the room is cleared
    void onClear();

    std::vector<std::shared_ptr<DynamicEntity>> getEntities();

    Collision getCollisionAfterMove(Vec2 currentPos, Vec2 directionToNextPos, unsigned int iter = 0);

    void updatePos(const Vec2& pos);
};

#endif // PROJPROG2022_ROOM_H
