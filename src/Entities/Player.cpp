//
// Created by yami2200 on 19/05/22.
//

#include "Player.h"

Player::Player(Vec2 &pos) : DynamicEntity(pos) {

}

void Player::update() {
    const Vec2 & mouse = Input::getInstance().getMousePos();
    const double dist_mouse_pos = mouse.distance(this->getPos());
    const double current_max_speed = 0.0;
}
