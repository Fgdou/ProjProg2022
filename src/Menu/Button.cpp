//
// Created by fgdou on 5/20/22.
//

#include "Button.h"
#include "../Input.h"
#include "../Rooms/Collision.h"
#include "../Renderer.h"
#include "../Theme.h"

Button::Button(Vec2 &pos, const Vec2 &size, const std::string &str, bool clickable)
    : name(str), clicked(false), hovered(false), pos(pos), size(size), clickable(clickable)
{}

void Button::update() {
    if(!clickable)
        return;

    auto mousePos = Input::getInstance().getMousePos();

    auto res = Collision::getPointInsideRectCollision(mousePos, pos-size/2, pos+size/2);
    hovered = res.isColliding;

    if(hovered && Input::getInstance().hasBeenPressedOnce(Input::MouseLeft))
        clicked = true;
}

void Button::draw() {
    if(!hovered) {
        Renderer::getInstance().drawRect(pos, size, Theme::button);
        Renderer::getInstance().drawText(name, pos, size.y/2, Theme::text);
    }else {
        Renderer::getInstance().drawRect(pos, size * 1.2, Theme::button_hovered);
        Renderer::getInstance().drawText(name, pos, size.y/2 * 1.2, Theme::text);
    }
}

bool Button::hasBeenClicked() {
    if(clicked){
        clicked = false;
        return true;
    }
    return false;
}

const std::string &Button::getName() const {
    return name;
}
