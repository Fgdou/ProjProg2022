//
// Created by fgdou on 5/20/22.
//

#include "Menu.h"

void Menu::update() {
    for(auto& b : buttons)
        b.update();
}

void Menu::draw() {
    for(auto& b : buttons)
        b.draw();
}

const std::string & Menu::getSelected() {
    for(auto& b : buttons){
        if(b.hasBeenClicked())
            return b.getName();
    }
}

Menu::Menu()
    : buttons()
{
    Vec2 pos{0, 0};
    Vec2 size{100, 50};
    buttons.emplace_back(
            pos,
            size,
            "Play",
            true
            );
}
