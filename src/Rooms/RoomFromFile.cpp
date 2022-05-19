//
// Created by fgdou on 5/19/22.
//

#include "RoomFromFile.h"

#include <utility>
#include <fstream>

std::vector<std::string> openFile(const std::string& path){
    std::ifstream file;
    file.open(path);
    if(!file.is_open())
        throw std::runtime_error("Failed to open file" + path);

    std::vector<std::string> vec;

    while(file){
        char cline[100];
        file.getline(cline, 100);
        std::string line(cline);
        vec.emplace_back(line);
    }

    file.close();

    return vec;
}

std::vector<std::string> getRoomStrings(const std::vector<std::string>& file){
    int cnt = 0;
    for(int i=0; i<file.size(); i++){
        if(file[i].empty()) {
            cnt = i;
            break;
        }
    }

    std::vector<std::string> vec(file.begin(), file.begin()+cnt);

    return vec;
}

std::vector<std::shared_ptr<Wall>> getWalls(const std::vector<std::string>& list){
    std::vector<std::shared_ptr<Wall>> walls;
    for(int i=0; i<list.size(); i++){
        for(auto j=0; j<list[i].length(); j++){
            char c = list[i][j];
            if(c == '#'){
                Vec2 pos((j+1.5) * Renderer::getSize().x/list[0].length() - Renderer::getSize().x/2
                         , (i+1.5)*Renderer::getSize().y/list.size() - Renderer::getSize().y/2);
                Vec2 size{Renderer::getSize().x/list[0].length()*2+5, Renderer::getSize().y/list.size()*2+5};
                walls.emplace_back(std::make_shared<Wall>(pos, size));
            }
        }
    }
    return walls;
}

std::shared_ptr<Room> RoomFromFile::getRoom(const std::string &path, World& world) {
    auto list = openFile(path);
    auto roomList = getRoomStrings(list);
    auto walls = getWalls(roomList);

    std::vector<std::shared_ptr<DynamicEntity>> entities;

    std::shared_ptr<Room> res = std::make_shared<Room>(entities, walls, world);

    return res;

}