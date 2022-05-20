//
// Created by fgdou on 5/19/22.
//

#include "RoomFromFile.h"
#include "../Entities/Chest.h"
#include "../Items/BasicSword.h"
#include "../Entities/BaseEnemy.h"
#include "../Entities/Enemies/SillyEnemy.h"
#include "../Items/SpinItem.h"

#include <utility>
#include <fstream>
#include <iostream>

std::vector<std::string> openFile(const std::string &path)
{
    std::ifstream file;
    file.open(path);
    if (!file.is_open())
        throw std::runtime_error("Failed to open file" + path);

    std::vector<std::string> vec;

    while (file)
    {
        char cline[100];
        file.getline(cline, 100);
        std::string line(cline);
        vec.emplace_back(line);
    }

    file.close();

    return vec;
}

std::vector<std::string> getRoomStrings(const std::vector<std::string> &file)
{
    int cnt = 0;
    for (int i = 0; i < file.size(); i++)
    {
        if (file[i].empty())
        {
            cnt = i;
            break;
        }
    }

    std::vector<std::string> vec(file.begin(), file.begin() + cnt);

    return vec;
}

std::vector<std::shared_ptr<Wall>> getWalls(const std::vector<std::string> &list)
{
    std::vector<std::shared_ptr<Wall>> walls;
    for (int i = 0; i < list.size(); i++)
    {
        for (auto j = 0; j < list[i].length(); j++)
        {
            char c = list[i][j];
            if (c == '#')
            {
                Vec2 pos((j)*Renderer::getSize().x / list[0].length() - Renderer::getSize().x / 2, (i)*Renderer::getSize().y / list.size() - Renderer::getSize().y / 2);
                Vec2 size{Renderer::getSize().x / list[0].length() + 5, Renderer::getSize().y / list.size() + 5};
                walls.emplace_back(std::make_shared<Wall>(pos, size));
            }
        }
    }
    return walls;
}

std::vector<std::shared_ptr<DynamicEntity>> getEntitiess(const std::vector<std::string> &list)
{
    std::vector<std::shared_ptr<DynamicEntity>> entities;
    for (int i = 0; i < list.size(); i++)
    {
        for (auto j = 0; j < list[i].length(); j++)
        {
            char c = list[i][j];
            if (c == 'c')
            {
                Vec2 pos((j + .5) * Renderer::getSize().x / list[0].length() - Renderer::getSize().x / 2, (i + .5) * Renderer::getSize().y / list.size() - Renderer::getSize().y / 2);
                Vec2 size{Renderer::getSize().x / list[0].length(), Renderer::getSize().y / list.size()};
                auto item =std::make_shared<SpinItem>(SpinItem({"../assets/swordSpin.png"}, {"../assets/SwordDouble.png"}, Vec2(7, 15),Vec2(6 * 3.387, 6 * 5), 1.0, 10.0, 80, 1.0));
                // std::make_shared<SpinItem>(SpinItem({"../assets/sword.png"}, {"../assets/SwordDouble.png"}, Vec2(2*7, 2*15),Vec2(2*6 * 3.387, 2*6 * 5), 1.0, 10.0, 80, 1.0));
                auto chest = std::make_shared<Chest>(pos, size, item);
                entities.emplace_back(std::dynamic_pointer_cast<DynamicEntity>(chest));
            }
            else if (c == 'm')
            {
                Vec2 pos((j + .5) * Renderer::getSize().x / list[0].length() - Renderer::getSize().x / 2, (i + .5) * Renderer::getSize().y / list.size() - Renderer::getSize().y / 2);
                auto monster = std::make_shared<BaseEnemy>(pos, 30.0, 15);
                entities.emplace_back(std::dynamic_pointer_cast<DynamicEntity>(monster));
            }
            else if (c == 's')
            {
                Vec2 pos((j + .5) * Renderer::getSize().x / list[0].length() - Renderer::getSize().x / 2, (i + .5) * Renderer::getSize().y / list.size() - Renderer::getSize().y / 2);
                auto monster = std::make_shared<SillyEnemy>(pos, 30.0, 15);
                entities.emplace_back(std::dynamic_pointer_cast<DynamicEntity>(monster));
            }
        }
    }
    return entities;
}

std::shared_ptr<Room> RoomFromFile::getRoom(const std::string &path, World &world)
{
    auto list = openFile(path);
    auto roomList = getRoomStrings(list);
    auto walls = getWalls(roomList);
    auto entities = getEntitiess(roomList);

    std::shared_ptr<Room> res = std::make_shared<Room>(entities, walls, world);

    return res;
}
