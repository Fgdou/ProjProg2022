//
// Created by fgdou on 5/19/22.
//

#include "AnimateRoom.h"
#include "../Maths/Timer.h"

AnimateRoom::AnimateRoom(double duration, const Vec2& from, const Vec2& to)
    : Animation(duration), from(from), to(to)
{}

void AnimateRoom::draw() {
}

void AnimateRoom::update() {
    Animation::update();
    auto pos = from + (to-from)*getAvancement();

    Renderer::getInstance().getCamera().setPos(pos);
}
