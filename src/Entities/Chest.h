//
// Created by fgdou on 5/19/22.
//

#ifndef PROJPROG2022_CHEST_H
#define PROJPROG2022_CHEST_H


#include "Entity.h"
#include "../Items/EquippableItem.h"

class Chest : public DynamicEntity {
public:
    Chest(Vec2 &pos, Vec2& size, std::shared_ptr<EquippableItem> item);

    void draw() override;

    void update(Room &room) override;

private:
    std::shared_ptr<EquippableItem> item;
    Image t_open, t_close;
    Vec2 size;
};


#endif //PROJPROG2022_CHEST_H
