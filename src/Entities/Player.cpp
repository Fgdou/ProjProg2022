//
// Created by yami2200 on 19/05/22.
//

#include <iostream>
#include "Player.h"
#include "../Maths/Timer.h"
#include "../Items/EquippableItem.h"
#include "../Rooms/Room.h"
#include "../Items/BasicSword.h"
#include "../Items/SpinItem.h"
#include "BaseEnemy.h"

Player::Player(Vec2 pos)
: DamageableEntity(pos, 100.0), damage(1.0),
    movement_vector(Vec2(10, 10).normalize()), speed(2.0),
    max_speed(20.0), acceleration(20.0), deceleration(30.0), rotAngle(10),
    current_item(-1), inventory(std::vector<std::shared_ptr<EquippableItem>>()),
    decelerationReboundMultiplier(0.5), sprite(Image("../assets/player.png")),
    lifeBar(*this),
    resistance(0)
{
    this->lootEquippableItem(std::make_shared<SpinItem>(SpinItem({"../assets/stick.png"}, Vec2(10.0, 150.0), 1.0, 10.0, 80, 1.0)));
    //this->lootEquippableItem(std::make_shared<BasicSword>(BasicSword({"../assets/sword.png"}, Vec2(30.0, 150.0), 0.5, 10.0, 80, 120.0)));
}

void Player::update(Room & room) {
    // Movement
    const Vec2 & mouse = Input::getInstance().getMousePos();
    const double dist_mouse_pos = mouse.distance(this->getPos());
    const double current_aim_speed = this->max_speed * std::max(std::min(1.0, (dist_mouse_pos / 500.0)), 0.3);

    double current_speed_multiply = (this->speed < current_aim_speed ? this->speed + (this->acceleration * Timer::getDeltaTime()) : this->speed - (this->deceleration * Timer::getDeltaTime()));
    current_speed_multiply = std::max(current_speed_multiply, 0.3*this->max_speed);
    current_speed_multiply = std::min(current_speed_multiply, this->max_speed);

    const double angle_mouse = this->movement_vector.angleBetween(this->getPos().lookAt(mouse));
    if(std::abs(angle_mouse) > std::abs(this->rotAngle * Timer::getDeltaTime())){
        this->movement_vector = this->movement_vector.rotate((angle_mouse < 0 ? (-this->rotAngle) * Timer::getDeltaTime() : this->rotAngle * Timer::getDeltaTime())).normalize();
    }

    Vec2 vec_move = this->movement_vector*current_speed_multiply;
    auto c = room.getCollisionAfterMove(this->position, vec_move);
    if(c.isColliding){
        this->setPos(c.newPos);
        this->movement_vector = c.newDir.normalize();
        this->speed = current_speed_multiply * this->decelerationReboundMultiplier;
    } else {
        this->setPos(this->getPos() + vec_move);
    }
    this->speed = current_speed_multiply;

    // Input
    if(Input::getInstance().isPressed(Input::MouseLeft)){
        std::cout << "click" << std::endl;
        if(this->currentItemValid()){
            std::cout << "use" << std::endl;
            this->inventory[this->current_item]->use(*this, room.getEntities());
        }
    }

    // Inventory items update
    for(auto& item : this->inventory){
        item->update(*this, room.getEntities());
    }

    // Check Ennemy near you
    for(auto & entity : room.getEntities()){
        if(entity->getPos().distance(this->getPos()) < 30){
            if (auto * e = dynamic_cast<BaseEnemy*>(entity.get()))
            {
                if(e->canAttack()){
                    this->takeDamage(e->getDamage());
                    e->hasAttackedPlayer();
                }
            }
        }
    }

}

void Player::draw() {
    double squish = std::max(std::min(0.4 + (1 - (speed/(max_speed - 0.3 * max_speed))), 1.0),0.0);
    Renderer::getInstance().drawImage(sprite, getPos(), Vec2(30, 10*squish+20), Vec2::toDegrees(this->movement_vector.angle()));
    Renderer::getInstance().drawLine(this->getPos(), this->getPos() + this->getPos().lookAt(Input::getInstance().getMousePos())*200.0);
    Renderer::getInstance().drawLine(this->getPos(), this->getPos() + this->movement_vector*this->speed, {0,255,0, 255});
    if(this->currentItemValid()){
        this->inventory[this->current_item]->draw(this->position);
    }
    lifeBar.draw();
}

Vec2 &Player::getDirection() {
    return this->movement_vector;
}

double Player::getDamage() {
    return this->damage;
}

void Player::lootEquippableItem(std::shared_ptr<EquippableItem> item) {
    this->inventory.push_back(item);
    this->current_item = this->inventory.size() -1;
}

bool Player::currentItemValid() {
    return this->current_item != -1 && this->current_item < this->inventory.size();
}

void Player::dead() {
    isDead = true;
}

void Player::takeDamage(double damage) {
    DamageableEntity::takeDamage(damage);
}

