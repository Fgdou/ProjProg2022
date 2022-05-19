//
// Created by fgdou on 5/19/22.
//

#ifndef PROJPROG2022_INPUT_H
#define PROJPROG2022_INPUT_H


#include "Maths/Vec2.h"
#include <SDL2/SDL.h>
#include <map>

class Input {
public:
    enum Inputs{
        MouseLeft,
        MouseRight,
        MouseMiddle,
        escape,
    };

    void operator=(const Input&) = delete;

    void update();
    const Vec2& getMousePos();
    bool isPressed(Inputs input);
    bool hasBeenPressedOnce(Inputs input);

    static Input& getInstance();

private:
    void setButtonTrue(Inputs i);

    std::map<Inputs, bool> inputs;
    std::map<Inputs, bool> pressedOnce;
    Vec2 mousePos;

    static std::unique_ptr<Input> ptr;
};


#endif //PROJPROG2022_INPUT_H
