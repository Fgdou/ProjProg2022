//
// Created by yami2200 on 20/05/22.
//

#ifndef PROJPROG2022_BLOOD_H
#define PROJPROG2022_BLOOD_H

#include "../Entities/DamageableEntity.h"

class Blood : public DamageableEntity{
private:
    Vec2 dir_point;
    double size;

public:
    Blood(Vec2 pos, Vec2 dir, double size, double life);

    void takeDamage(double damage) override;

    void update(Room &room) override;

    void draw() override;
};


#endif //PROJPROG2022_BLOOD_H
