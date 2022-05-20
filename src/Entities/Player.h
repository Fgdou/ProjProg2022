//
// Created by yami2200 on 19/05/22.
//

#ifndef PROJPROG2022_PLAYER_H
#define PROJPROG2022_PLAYER_H

#include <vector>
#include "DamageableEntity.h"
#include "../Input.h"
#include "../Image.h"
#include "LifeBar.h"

class EquippableItem;

class Player : public DamageableEntity {
private:
    Image sprite;

    // Movement Management
    double max_speed;
    double speed;
    double acceleration;
    Vec2 movement_vector;
    double deceleration;
    double rotAngle;
public:
    void takeDamage(double damage) override;

private:
    double decelerationReboundMultiplier;

    // Stats
    double damage;
    double resistance;

    // Items
    std::vector<std::shared_ptr<EquippableItem>> inventory;
    int current_item;
    bool currentItemValid();
    bool hasSwitched;

    LifeBar lifeBar;


public:
    Player(Vec2 pos);

    void update(Room & room) override;

    void draw() override;

    Vec2 & getDirection();

    double getDamage();

    void lootEquippableItem(std::shared_ptr<EquippableItem> item);

    void dead() override;

    void switchItem();
};


#endif //PROJPROG2022_PLAYER_H
