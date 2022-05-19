//
// Created by yami2200 on 19/05/22.
//

#include <iostream>
#include "Player.h"
#include "../Maths/Timer.h"
#include "../Items/EquippableItem.h"

Player::Player(Vec2 pos) : DamageableEntity(pos, 100.0), acceleration(1), deceleration(2), current_item(-1), inventory(std::vector<std::shared_ptr<EquippableItem>>()) {

}

void Player::update(Room & room) {
    // Movement
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

    // Input
    if(Input::getInstance().isPressed(Input::MouseLeft)){
        if(this->currentItemValid()){
            this->inventory[this->current_item]->use(*this, room.getEntities());
        }
    }

    getPos().print();
}

void Player::draw() {
    Renderer::getInstance().drawCircle(this->getPos(),3.0, {255,0,0, 255});
    if(this->currentItemValid()){
        this->inventory[this->current_item]->draw(this->position);
    }
}

Vec2 &Player::getDirection() {
    return this->movement_vector;
}

double Player::getDamage() {
    return this->damage;
}

void Player::lootEquippableItem(std::shared_ptr<EquippableItem> item) {
    this->inventory.push_back(item);
    if(this->current_item == -1){
        this->current_item = 0;
    }
}

bool Player::currentItemValid() {
    return this->current_item != -1 && this->current_item < this->inventory.size();
}

void Player::dead() {
    std::cout << "Fin frérot, tu es mort" << std::endl;
}
