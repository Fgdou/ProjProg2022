//
// Created by fgdou on 5/19/22.
//

#ifndef PROJPROG2022_INPUT_H
#define PROJPROG2022_INPUT_H


#include "Maths/Vec2.h"

class Input {
public:
    enum class Inputs{
        MouseLeft,
        MouseRight,
        MouseMiddle,
        up,
        down,
        left,
        right,
        jump,
        escape,
    };

    virtual void update() = 0;
    virtual const Vec2& getMousePos() = 0;
    virtual bool isPressed(Inputs input) = 0;
    virtual bool hasBeenPressedOnce(Inputs input) = 0;
};


#endif //PROJPROG2022_INPUT_H
