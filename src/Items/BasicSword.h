//
// Created by yami2200 on 19/05/22.
//

#ifndef PROJPROG2022_BASICSWORD_H
#define PROJPROG2022_BASICSWORD_H

#include "EquippableItem.h"

class BasicSword : public EquippableItem {
protected:
    double angle;
public:

    BasicSword(Image sprite, double damage, double angle);

    void use(Player & player, std::vector<std::shared_ptr<DynamicEntity>> v_entities) override;
};


#endif //PROJPROG2022_BASICSWORD_H
