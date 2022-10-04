//
// Created by guill on 20/05/2022.
//

#ifndef PROJPROG2022_SILLYENEMY_H
#define PROJPROG2022_SILLYENEMY_H

#include "BaseEnemy.h"


class SillyEnemy : public BaseEnemy {
private:
    double angle;
    double current_angle;
    bool forward;

    Image image;
    Image imageHurt;

public:
    void  update(Room & room);

    SillyEnemy(Vec2 & pos, double lifemax, double damage);

    void draw() override;
};


#endif //PROJPROG2022_SILLYENEMY_H
