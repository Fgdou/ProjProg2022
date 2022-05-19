//
// Created by guill on 19/05/2022.
//

#ifndef PROJPROG2022_KEYDOOR_H
#define PROJPROG2022_KEYDOOR_H


#include "Door.h"

class KeyDoor : public Wall {
protected:
    char key;
    bool closed;
public:
    KeyDoor(char key = '0', Vec2 pos = (0,0), Vec2 size = (0,0), bool closed=1);
    void giveKey(char key);
    void draw();
};


#endif //PROJPROG2022_KEYDOOR_H
