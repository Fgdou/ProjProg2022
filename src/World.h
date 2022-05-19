//
// Created by fgdou on 5/19/22.
//

#ifndef PROJPROG2022_WORLD_H
#define PROJPROG2022_WORLD_H

#include "Rooms/Room.h"

class World {
private:
    std::vector<std::vector<Room>> rooms;
public:
    void render();
    void update();
};


#endif //PROJPROG2022_WORLD_H
