//
// Created by fgdou on 5/19/22.
//

#ifndef PROJPROG2022_ROOMFROMFILE_H
#define PROJPROG2022_ROOMFROMFILE_H


#include "Room.h"

class RoomFromFile : public Room {
public:
    static std::shared_ptr<Room> getRoom(const std::string& path, World& world);
};


#endif //PROJPROG2022_ROOMFROMFILE_H
