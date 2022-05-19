//
// Created by fgdou on 5/19/22.
//

#ifndef PROJPROG2022_WORLD_H
#define PROJPROG2022_WORLD_H

#include "Rooms/Room.h"
#include "Entities/Player.h"

class World {
private:
    std::vector<std::vector<std::shared_ptr<Room>>> rooms;
    std::shared_ptr<Player> player;
    Vec2 selectedRoom;
public:
    World(Vec2 size);

    void addRoom(const std::shared_ptr<Room>& room, Vec2 pos);

    const Vec2& getSelectedRoom();
    void setSelectedRoom(Vec2 room);
    std::shared_ptr<Player> getPlayer();

    void draw();
    void update();
};


#endif //PROJPROG2022_WORLD_H
