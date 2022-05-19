//
// Created by fgdou on 5/19/22.
//

#include "Input.h"

std::unique_ptr<Input> ptr;

Input &Input::getInstance() {
    if(ptr == nullptr)
        ptr = std::make_unique<Input>();
    return *ptr;
}

bool Input::isPressed(Input::Inputs input) {
    return inputs[input];
}

bool Input::hasBeenPressedOnce(Input::Inputs input) {
    if(pressedOnce[input]){
        pressedOnce[input] = false;
        return true;
    }
    return false;
}

const Vec2 &Input::getMousePos() {
    return mousePos;
}

void Input::update() {

    SDL_Event e;
    SDL_PollEvent(&e);

    if(e.type == SDL_MOUSEMOTION){
        mousePos = Vec2(
                e.motion.x,
                e.motion.y
        ).screenToWorld();
    }else if(e.type == SDL_MOUSEBUTTONDOWN){
        if(e.button.button == SDL_BUTTON_LEFT)
            setButtonTrue(MouseLeft);
        else if(e.button.button == SDL_BUTTON_RIGHT)
            setButtonTrue(MouseRight);
        else if(e.button.button == SDL_BUTTON_MIDDLE)
            setButtonTrue(MouseMiddle);
    }else if(e.type == SDL_MOUSEBUTTONUP){
        if(e.button.button == SDL_BUTTON_LEFT)
            inputs[MouseLeft] = false;
        else if(e.button.button == SDL_BUTTON_RIGHT)
            inputs[MouseRight] = false;
        else if(e.button.button == SDL_BUTTON_MIDDLE)
            inputs[MouseMiddle] = false;
    }else if(e.type == SDL_KEYDOWN){
        if(e.key.keysym.sym == SDLK_ESCAPE)
            setButtonTrue(escape);
    }else if(e.type == SDL_KEYUP){
        if(e.key.keysym.sym == SDLK_ESCAPE)
            inputs[escape] = false;
    }
}

void Input::setButtonTrue(Input::Inputs i) {
    inputs[i] = true;
    pressedOnce[i] = true;
}
