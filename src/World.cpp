//
// Created by fgdou on 5/19/22.
//

#include "World.h"
#include "Rooms/Room.h"
#include "Rooms/RoomFromFile.h"
#include "Theme.h"

World::World()
    : player(std::make_shared<Player>(Vec2{-500, 0})), selectedRoom({0, 0}), BG_color(Theme::background)
{
    Vec2 size = {3, 2};
    rooms.resize(size.y);
    for (auto &v : rooms)
    {
        v.resize(size.x);
    }

    setSelectedRoom({0, 0});

    rooms[0][0] = RoomFromFile::getRoom("../assets/level/level1.txt", *this);
    rooms[0][1] = RoomFromFile::getRoom("../assets/level/level2.txt", *this);
    rooms[0][2] = RoomFromFile::getRoom("../assets/level/level3.txt", *this);
    rooms[1][2] = RoomFromFile::getRoom("../assets/level/level4.txt", *this);
    rooms[1][1] = RoomFromFile::getRoom("../assets/level/level5.txt", *this);
    rooms[1][0] = RoomFromFile::getRoom("../assets/level/level6.txt", *this);
    updateRoomPos();

}

Room &World::getPlayerRoom()
{
    return *rooms[selectedRoom.y][selectedRoom.x];
}

void World::setSelectedRoom(const Vec2 &room)
{

    if (room.x < 0 || room.x >= rooms[0].size() || room.y < 0 || room.y >= rooms.size())
        return;

    auto from = selectedRoom * Renderer::getSize();
    auto to = room * Renderer::getSize();

    selectedRoomTransition = selectedRoom;
    selectedRoom = room;

    roomAnimation = std::make_shared<AnimateRoom>(1, from, to);
}

std::shared_ptr<Player> World::getPlayer()
{
    return player;
}

void World::addRoom(const std::shared_ptr<Room> &room, Vec2 pos)
{
    rooms[pos.y][pos.x] = room;
}

void World::draw()
{
    Renderer::getInstance().drawRect((Renderer::getSize() / 2).screenToWorld(), Renderer::getSize() * Vec2(2).screenToWorld(), BG_color);
    if (roomAnimation != nullptr)
    {
        roomAnimation->draw();
        auto room2 = rooms[selectedRoomTransition.y][selectedRoomTransition.x];
        if (room2 == nullptr)
            return;
        room2->draw();
    }

    auto room = rooms[selectedRoom.y][selectedRoom.x];
    if (room == nullptr)
        return;
    room->draw();
    player->draw();
}

void World::update()
{

    if (roomAnimation != nullptr)
    {
        if (roomAnimation->running())
        {
            roomAnimation->update();
        }
        else
        {
            roomAnimation = nullptr;
        }
        return;
    }

    auto room = rooms[selectedRoom.y][selectedRoom.x];
    if (room == nullptr)
        return;
    player->update(*room);
    room->update();

    // Change room
    auto screenSize = Renderer::getSize();
    Vec2 ScreenPos = player->getPos().worldToScreen();
    if (ScreenPos.x >= screenSize.x)
    {
        setSelectedRoom(selectedRoom + Vec2{1, 0});
    }
    else if (ScreenPos.x < 0)
    {
        setSelectedRoom(selectedRoom + Vec2{-1, 0});
    }
    else if (ScreenPos.y >= screenSize.y)
    {
        setSelectedRoom(selectedRoom + Vec2{0, 1});
    }
    else if (ScreenPos.y < 0)
    {
        setSelectedRoom(selectedRoom + Vec2{0, -1});
    }

    Renderer::getInstance().funMeter *= 0.96;

    if (Renderer::getInstance().funMeter < 0)
    {
        BG_color.r = Theme::background.r * (1 + (Renderer::getInstance().funMeter / 100)) + Theme::background_low.r * (- Renderer::getInstance().funMeter / 100);
        BG_color.g = Theme::background.g * (1 + (Renderer::getInstance().funMeter / 100)) + Theme::background_low.g * (- Renderer::getInstance().funMeter / 100);
        BG_color.b = Theme::background.b * (1 + (Renderer::getInstance().funMeter / 100)) + Theme::background_low.b * (- Renderer::getInstance().funMeter / 100);
    }
    else if (Renderer::getInstance().funMeter > 0)
    {
        BG_color.r = Theme::background.r * (1 - (Renderer::getInstance().funMeter / 100)) + Theme::background_high.r * (Renderer::getInstance().funMeter / 100);
        BG_color.g = Theme::background.g * (1 - (Renderer::getInstance().funMeter / 100)) + Theme::background_high.g * (Renderer::getInstance().funMeter / 100);
        BG_color.b = Theme::background.b * (1 - (Renderer::getInstance().funMeter / 100)) + Theme::background_high.b * (Renderer::getInstance().funMeter / 100);
    }
}

void World::updateRoomPos()
{
    for (int i = 0; i < rooms.size(); ++i)
    {
        for (int j = 0; j < rooms[i].size(); ++j)
        {
            if (rooms[i][j] == nullptr)
                continue;
            Vec2 pos = Vec2(j, i) * Renderer::getSize();
            rooms[i][j]->updatePos(pos);
        }
    }
}

bool World::isDead()
{
    return player->isDead1();
}

bool World::hasWin() {
    return cntEnemies() == 0;
}

int World::cntEnemies() {
    int cnt = 0;
    for(auto& v : rooms){
        for(auto& r : v){
            cnt += r->cntMonsters();
        }
    }
    return cnt;
}
