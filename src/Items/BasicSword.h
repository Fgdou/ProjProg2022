//
// Created by yami2200 on 19/05/22.
//

#ifndef PROJPROG2022_BASICSWORD_H
#define PROJPROG2022_BASICSWORD_H

#include "EquippableItem.h"

class BasicSword : public EquippableItem {
protected:
    double angle;
    double length;
    double current_angle;
    bool in_anim;
    Vec2 relative_position;
    double relative_rotation;
public:

    BasicSword(Image sprite, Vec2 size, double cooldown, double damage, double angle, double length);

    void use(Player & player, std::vector<std::shared_ptr<DynamicEntity>> v_entities) override;

    void draw(Vec2 &pos) override;

    void update() override;
};


#endif //PROJPROG2022_BASICSWORD_H
