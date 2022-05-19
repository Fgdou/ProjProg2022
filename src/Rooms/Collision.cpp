//
// Created by guill on 19/05/2022.
//

#include "Collision.h"

Collision::Collision(bool collide, Vec2 impact, Vec2 rebound): collide(collide), impact(impact), rebound(rebound) {

}
bool Collision::isCollide() const {
    return collide;
}

const Vec2 &Collision::getImpact() const {
    return impact;
}

const Vec2 &Collision::getRebound() const {
    return rebound;
}
