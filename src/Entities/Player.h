//
// Created by yami2200 on 19/05/22.
//

#ifndef PROJPROG2022_PLAYER_H
#define PROJPROG2022_PLAYER_H


#include "DynamicEntity.h"
#include "../Input.h"

class Player : public DynamicEntity {
private:
    double max_speed;
    double acceleration;
    Vec2 movement_vector;
    double deceleration;

public:
    Player(Vec2 & pos);

    void update() override;
};


#endif //PROJPROG2022_PLAYER_H
