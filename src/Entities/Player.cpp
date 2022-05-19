//
// Created by yami2200 on 19/05/22.
//

#include "Player.h"
#include "../Renderer.h"
#include "../Maths/Timer.h"

Player::Player(Vec2 &pos) : DamageableEntity(pos, 100.0), acceleration(1), deceleration(2) {

}

void Player::update(Room & room) {
    const Vec2 & mouse = Input::getInstance().getMousePos();
    const double dist_mouse_pos = mouse.distance(this->getPos());
    const double current_aim_speed_multiply = this->max_speed * std::min(std::min(0.3, (dist_mouse_pos / 500)), 1.0);
    const double current_speed_multiply = (this->speed < current_aim_speed_multiply ? this->speed + (this->acceleration * Timer::getDeltaTime()) : this->speed - (this->deceleration * Timer::getDeltaTime()));
    const double angle_mouse = this->movement_vector.angleBetween(this->getPos().lookAt(mouse));
    this->movement_vector.rotate((angle_mouse < 0 ? (-this->rotAngle) * Timer::getDeltaTime() : this->rotAngle * Timer::getDeltaTime()));
    Vec2 vec_move = this->movement_vector*current_speed_multiply;
    auto c = room.getPlayerCollision(this->position, vec_move);
    if(c.isCollide()){
        this->setPos(c.getImpact());
        this->movement_vector = c.getRebound().normalize();
    } else {
        this->setPos(this->getPos() + this->movement_vector*current_speed_multiply);
    }
    this->speed = current_speed_multiply;
}

void Player::draw() {
    Renderer::getInstance().drawCircle(this->getPos(),3.0, {255,0,0, 255});
}