//
// Created by fgdou on 5/19/22.
//

#ifndef PROJPROG2022_LIFEBAR_H
#define PROJPROG2022_LIFEBAR_H

class Player;

class LifeBar {
public:
    LifeBar(Player& p);

    void draw();

private:
    Player& p;
};


#endif //PROJPROG2022_LIFEBAR_H
