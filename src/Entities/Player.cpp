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
#include "Enemies/BaseEnemy.h"
#include "Enemies/Boss.h"

Player::Player(Vec2 pos)
    : DamageableEntity(pos, 100.0), damage(1.0),
      movement_vector(Vec2(10, 10).normalize()), speed(2.0),
      max_speed(20.0), acceleration(20.0), deceleration(30.0), rotAngle(10),
      current_item(-1), inventory(std::vector<std::shared_ptr<EquippableItem>>()),
      decelerationReboundMultiplier(0.5), sprite(Image("../assets/player.png")),
      lifeBar(*this),
      resistance(0),
      hasSwitched(false)
{
    //this->lootEquippableItem(std::make_shared<SpinItem>(SpinItem({"../assets/sword.png"}, {"../assets/SwordDouble.png"}, Vec2(7, 15),Vec2(6 * 3.387, 6 * 5), 1.0, 10.0, 80, 1.0)));
    //this->lootEquippableItem(std::make_shared<BasicSword>(BasicSword({"../assets/sword.png"}, Vec2(30.0, 150.0), 0.5, 10.0, 80, 120.0)));
}

void Player::update(Room &room)
{
    // Movement
    const Vec2 &mouse = Input::getInstance().getMousePos();
    const double dist_mouse_pos = mouse.distance(this->getPos());
    const double current_aim_speed = this->max_speed * std::max(std::min(1.0, (dist_mouse_pos / 500.0)), 0.3);

    double current_speed_multiply = (this->speed < current_aim_speed ? this->speed + (this->acceleration * Timer::getDeltaTime()) : this->speed - (this->deceleration * Timer::getDeltaTime()));
    current_speed_multiply = std::max(current_speed_multiply, 0.3 * this->max_speed);
    current_speed_multiply = std::min(current_speed_multiply, this->max_speed);

    const double angle_mouse = this->movement_vector.angleBetween(this->getPos().lookAt(mouse));
    if (std::abs(angle_mouse) > std::abs(this->rotAngle * Timer::getDeltaTime()))
    {
        this->movement_vector = this->movement_vector.rotate((angle_mouse < 0 ? (-this->rotAngle) * Timer::getDeltaTime() : this->rotAngle * Timer::getDeltaTime())).normalize();
    }

    Vec2 vec_move = this->movement_vector * current_speed_multiply;
    auto c = room.getCollisionAfterMove(this->position, vec_move);
    if (c.isColliding)
    {
        Renderer::getInstance().funMeter = 20;
        this->setPos(c.newPos);
        this->movement_vector = c.newDir.normalize();
        this->speed = current_speed_multiply * this->decelerationReboundMultiplier;
    }
    else
    {
        this->setPos(this->getPos() + vec_move);
    }
    this->speed = current_speed_multiply;

    // Input
    if (Input::getInstance().hasBeenPressedOnce(Input::MouseLeft))
    {
        if (this->currentItemValid())
        {
            this->inventory[this->current_item]->use(*this, room.getEntities());
        }
    }
    if (Input::getInstance().isPressed(Input::MouseRight))
    {
        this->switchItem();
    } else if(this->hasSwitched) {
        this->hasSwitched = false;
    }

    // Inventory items update
    for (auto &item : this->inventory)
    {
        item->update(*this, room.getEntities());
    }

    // Check Ennemy near you
    for (auto &entity : room.getEntities())
    {
        if (auto *e = dynamic_cast<Boss *>(entity.get())) {
            if (entity->getPos().distance(this->getPos()) < e->getDistance()) {
                if (e->canDealDamage()) {
                    e->dealsDamage();
                    this->takeDamage(e->getDamage());
                    e->hasAttackedPlayer();
                    this->movement_vector = e->getPos().lookAt(this->getPos()).normalize();
                    this->speed *= 1.2;
                }
            } else if(entity->getPos().distance(this->getPos()) < 65){
                this->takeDamage(e->getDamage());
                e->hasAttackedPlayer();
                this->movement_vector = e->getPos().lookAt(this->getPos()).normalize();
                this->speed *= 1.2;
            }
        }
        else if (auto *e = dynamic_cast<BaseEnemy *>(entity.get()))
        {
            if (entity->getPos().distance(this->getPos()) < 40)
            {
                if (e->canAttack())
                {
                    this->takeDamage(e->getDamage());
                    e->hasAttackedPlayer();
                    this->movement_vector = e->getPos().lookAt(this->getPos()).normalize();
                    this->speed*=1.2;
                }
            }
        }
    }
}

void Player::draw()
{
    double squish = std::max(std::min(0.4 + (1 - (speed / (max_speed - 0.3 * max_speed))), 1.0), 0.0);
    Renderer::getInstance().drawImage(sprite, getPos(), Vec2(30, 10 * squish + 20), Vec2::toDegrees(this->movement_vector.angle()));

    if (this->currentItemValid())
    {
        this->inventory[this->current_item]->draw(this->position);
    }
    lifeBar.draw();
}

Vec2 &Player::getDirection()
{
    return this->movement_vector;
}

double Player::getDamage()
{
    return this->damage;
}

void Player::lootEquippableItem(std::shared_ptr<EquippableItem> item)
{
    this->inventory.push_back(item);
    this->current_item = this->inventory.size() - 1;
}

bool Player::currentItemValid()
{
    return this->current_item != -1 && this->current_item < this->inventory.size();
}

void Player::dead()
{
    isDead = true;
}

void Player::takeDamage(double damage)
{
    Renderer::getInstance().funMeter = -50;
    DamageableEntity::takeDamage(damage);
}

void Player::switchItem() {
    if(this->currentItemValid() && !this->hasSwitched){
        this->hasSwitched = true;
        if(this->current_item == this->inventory.size() -1){
            this->current_item = 0;
        } else {
            this->current_item++;
        }
    }
}
