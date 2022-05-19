//
// Created by yami2200 on 19/05/22.
//

#ifndef PROJPROG2022_PLAYER_H
#define PROJPROG2022_PLAYER_H

#include "DamageableEntity.h"
#include "../Input.h"

class Player : public DamageableEntity {
private:
    // Movement Management
    double max_speed;
    double acceleration;
    Vec2 movement_vector;
    double deceleration;

    // Stats
    double damage;
    double resistance;


public:
    Player(Vec2 & pos);

    void update(Room & room) override;

    void draw() override;
};


#endif //PROJPROG2022_PLAYER_H
