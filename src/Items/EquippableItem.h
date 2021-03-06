//
// Created by yami2200 on 19/05/22.
//

#ifndef PROJPROG2022_EQUIPPABLEITEM_H
#define PROJPROG2022_EQUIPPABLEITEM_H


#include "../Image.h"
#include "../Entities/DynamicEntity.h"
#include "../Entities/Player.h"

class EquippableItem {
protected:
    bool isEquipped;
    Image sprite;
    Vec2 size;
    double angle;
    double damage;
    double cooldown_max;
    double current_cooldown;

public:
    EquippableItem(Image sprite, Vec2 size, double cooldown, double damage = 0.0);

    virtual void draw(Vec2 & pos);

    virtual void use(Player & player, const std::vector<std::shared_ptr<DynamicEntity>>& v_entities);

    virtual void update(Player &player, const std::vector<std::shared_ptr<DynamicEntity>>& v_entities);

protected:
    double getPercentCooldown() const;
    void printProgressBar(const Vec2 &pos);
};


#endif //PROJPROG2022_EQUIPPABLEITEM_H
