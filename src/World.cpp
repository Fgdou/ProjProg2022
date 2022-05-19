//
// Created by fgdou on 5/19/22.
//

#include "World.h"
#include "Rooms/Room.h"
#include "Entities/Player.h"
#include "Rooms/RoomFromFile.h"


World::World()
    : player(std::make_shared<Player>(Vec2{0, 0})), selectedRoom({0, 0})
{
    Vec2 size = {2, 1};
    rooms.resize(size.y);
    for (auto& v : rooms) {
        v.resize(size.x);
    }

    auto room =
    rooms[0][0] = RoomFromFile::getRoom("../assets/level/level1.txt", *this);
    rooms[0][1] = RoomFromFile::getRoom("../assets/level/level2.txt", *this);
}

const Vec2 &World::getSelectedRoom() {
    return selectedRoom;
}

void World::setSelectedRoom(Vec2 room){
    selectedRoom = room;
}

std::shared_ptr<Player> World::getPlayer() {
    return player;
}

void World::addRoom(const std::shared_ptr<Room> &room, Vec2 pos) {
    rooms[pos.y][pos.x] = room;
}

void World::draw() {
    auto room = rooms[selectedRoom.y][selectedRoom.x];
    if(room == nullptr)
        return;
    room->draw();
    player->draw();
}

void World::update() {
    auto room = rooms[selectedRoom.y][selectedRoom.x];
    if(room == nullptr)
        return;
    player->update(*room);
    room->update();

    //Change room
    auto screenSize = Renderer::getSize();
    Vec2 ScreenPos = player->getPos().worldToScreen();
    if(ScreenPos.x >= screenSize.x){
        selectedRoom.x++;
    } else if( ScreenPos.x < 0){
        selectedRoom.x--;
    } else if( ScreenPos.y >= screenSize.y){
        selectedRoom.y++;
    } else if( ScreenPos.y < 0){
        selectedRoom.y--;
    }
}
