//
// Created by fgdou on 5/19/22.
//

#include "World.h"

World::World(Vec2 size)
    : player(std::make_shared<Player>(Vec2{0, 0})), selectedRoom({0, 0})
{
    rooms.resize(size.y);
    for (auto& v : rooms) {
        v.resize(size.x);
    }

    auto room = std::make_shared<Room>(std::vector<std::shared_ptr<DynamicEntity>>{}, std::vector<std::shared_ptr<Wall>>{});
    rooms[0][0] = room;
}

const Vec2 &World::getSelectedRoom() {
    return selectedRoom;
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
}
