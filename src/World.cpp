//
// Created by fgdou on 5/19/22.
//

#include "World.h"
#include "Rooms/Room.h"
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

    updateRoomPos();
}

const Vec2 &World::getSelectedRoom() {
    return selectedRoom;
}

void World::setSelectedRoom(const Vec2& room){

    auto from = getSelectedRoom()*Renderer::getSize();
    auto to = room*Renderer::getSize();

    selectedRoomTransition = selectedRoom;
    selectedRoom = room;


    roomAnimation = std::make_shared<AnimateRoom>(2, from, to);
}

std::shared_ptr<Player> World::getPlayer() {
    return player;
}

void World::addRoom(const std::shared_ptr<Room> &room, Vec2 pos) {
    rooms[pos.y][pos.x] = room;
}

void World::draw() {
    if(roomAnimation != nullptr) {
        roomAnimation->draw();
        auto room2 = rooms[selectedRoomTransition.y][selectedRoomTransition.x];
        if(room2 == nullptr)
            return;
        room2->draw();
    }

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

    if(roomAnimation != nullptr){
        if(roomAnimation->running()) {
            roomAnimation->update();
            auto room2 = rooms[selectedRoomTransition.y][selectedRoomTransition.x];
            if (room2 == nullptr)
                return;
            room2->update();
        }else{
            roomAnimation = nullptr;
        }
        return;
    }

    //Change room
    auto screenSize = Renderer::getSize();
    Vec2 ScreenPos = player->getPos().worldToScreen();
    if(ScreenPos.x >= screenSize.x){
        setSelectedRoom(selectedRoom + Vec2{1, 0});
    } else if( ScreenPos.x < 0){
        setSelectedRoom(selectedRoom + Vec2{-1, 0});
    } else if( ScreenPos.y >= screenSize.y){
        setSelectedRoom(selectedRoom + Vec2{0, 1});
    } else if( ScreenPos.y < 0){
        setSelectedRoom(selectedRoom + Vec2{0, -1});
    }
}

void World::updateRoomPos() {
    for (int i = 0; i < rooms.size(); ++i) {
        for (int j = 0; j < rooms[i].size(); ++j) {
            if(rooms[i][j] == nullptr)
                continue;
            Vec2 pos = Vec2(j, i) * Renderer::getSize();
            rooms[i][j]->updatePos(pos);
        }
    }
}
