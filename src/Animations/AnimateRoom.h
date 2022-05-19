//
// Created by fgdou on 5/19/22.
//

#ifndef PROJPROG2022_ANIMATEROOM_H
#define PROJPROG2022_ANIMATEROOM_H


#include "../Maths/Vec2.h"
#include "Animation.h"
#include "../World.h"

class AnimateRoom : public Animation {
public:
    AnimateRoom(double duration, const Vec2& from, const Vec2& to);

    void draw() override;

    void update() override;

private:
    Vec2 from, to;
};


#endif //PROJPROG2022_ANIMATEROOM_H
