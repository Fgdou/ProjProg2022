//
// Created by fgdou on 5/19/22.
//

#ifndef PROJPROG2022_WORLD_H
#define PROJPROG2022_WORLD_H

#include "Rooms/Room.h"
#include "Entities/Player.h"
#include "Animations/AnimateRoom.h"

class World {
private:
    std::vector<std::vector<std::shared_ptr<Room>>> rooms;
    std::shared_ptr<Player> player;
    Vec2 selectedRoom;
    Vec2 selectedRoomTransition;
    std::shared_ptr<Animation> roomAnimation;
public:
    World();

    void addRoom(const std::shared_ptr<Room>& room, Vec2 pos);

    Room& getPlayerRoom();
    void setSelectedRoom(const Vec2& room);
    std::shared_ptr<Player> getPlayer();

    void draw();
    void update();

private:
    void updateRoomPos();
};


#endif //PROJPROG2022_WORLD_H
