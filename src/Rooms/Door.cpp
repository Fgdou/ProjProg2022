//
// Created by guill on 19/05/2022.
//

#include "Door.h"


Door::Door(Vec2 pos, Vec2 size, bool closed): Wall(pos, size), closed(closed) {

}
void Door::open(){
    closed = false;
}

void Door::draw() {
    if(closed) {
        Wall::draw();
    }
}



