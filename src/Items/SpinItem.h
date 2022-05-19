//
// Created by yami2200 on 19/05/22.
//

#ifndef PROJPROG2022_SPINITEM_H
#define PROJPROG2022_SPINITEM_H

#include "EquippableItem.h"

class SpinItem : public EquippableItem{
private:
    double duration;
    bool in_anim;
    double length;
    double current_angle;

public:

    SpinItem(Image sprite, Vec2 size, double cooldown, double damage, double length, double duration);

    void use(Player & player, std::vector<std::shared_ptr<DynamicEntity>> v_entities) override;

    void draw(Vec2 &pos) override;

    void update() override;
};


#endif //PROJPROG2022_SPINITEM_H
