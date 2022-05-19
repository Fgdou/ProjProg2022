//
// Created by yami2200 on 19/05/22.
//

#ifndef PROJPROG2022_EQUIPPABLEITEM_H
#define PROJPROG2022_EQUIPPABLEITEM_H


#include "../Image.h"

class EquippableItem {
protected:
    bool isEquipped;
    Image sprite;
    Vec2 size;
    double angle;
    double damage;

public:
    EquippableItem(Image sprite, double damage = 0.0);

    virtual void draw(Vec2 & pos);



};


#endif //PROJPROG2022_EQUIPPABLEITEM_H
