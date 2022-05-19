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
    Image spin_sprite;
    Vec2 lastPos;
    Vec2 pos;
    Vec2 spin_size;

public:

    SpinItem(Image sprite, Image spin_sprite, Vec2 size, Vec2 spin_size, double cooldown, double damage, double length, double duration);

    void use(Player & player, const std::vector<std::shared_ptr<DynamicEntity>>& v_entities) override;

    void draw(Vec2 &pos) override;

    void update(Player &player, const std::vector<std::shared_ptr<DynamicEntity>>& v_entities) override;
};


#endif //PROJPROG2022_SPINITEM_H
