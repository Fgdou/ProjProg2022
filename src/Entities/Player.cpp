//
// Created by yami2200 on 19/05/22.
//

#include "Player.h"
#include "../Renderer.h"

Player::Player(Vec2 &pos) : DamageableEntity(pos, 100.0) {

}

void Player::update(Room & room) {
    const Vec2 & mouse = Input::getInstance().getMousePos();
    const double dist_mouse_pos = mouse.distance(this->getPos());
    const double current_speed_multiply = this->max_speed * std::min(std::min(0.3, (dist_mouse_pos / 500)), 1.0);


}

void Player::draw() {
    Renderer::getInstance().drawCircle(this->getPos(),3.0, {255,0,0, 255});
}
