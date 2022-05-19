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

    void update();
    const Vec2& getMousePos();
    bool isPressed(Inputs input);
    bool hasBeenPressedOnce(Inputs input);
};


#endif //PROJPROG2022_INPUT_H
