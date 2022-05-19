//
// Created by guill on 19/05/2022.
//

#include "KeyDoor.h"

KeyDoor::KeyDoor(char key, Vec2 pos, Vec2 size, bool closed): Wall(pos, size), key(key), closed(closed){

}

void KeyDoor::giveKey(char key) {
    if(key==this->key) closed = true;
}

void KeyDoor::draw() {
    if(closed) Wall::draw();
}