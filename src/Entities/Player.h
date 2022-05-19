//
// Created by yami2200 on 19/05/22.
//

#ifndef PROJPROG2022_PLAYER_H
#define PROJPROG2022_PLAYER_H


#include "DynamicEntity.h"

class Player : public DynamicEntity {
private:
    double vitesse_max;
    double acceleration;
    Vec2 vecteur_deplacement;
    double deceleration;

public:
    Player(Vec2 & pos);
};


#endif //PROJPROG2022_PLAYER_H
