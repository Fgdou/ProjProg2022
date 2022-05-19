//
// Created by fgdou on 5/19/22.
//

#include "Entity.h"

void Entity::setPos(const Vec2 &pos) {
    this->position = pos;
}

const Vec2 &Entity::getPos() {
    return this->position;
}
