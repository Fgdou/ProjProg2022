//
// Created by fgdou on 5/20/22.
//

#include "Menu.h"

#include <utility>
#include "../Renderer.h"
#include "../Theme.h"

void Menu::update() {
    for(auto& b : buttons)
        b.update();
}

void Menu::draw() {
    auto size = Renderer::getSize();
    auto pos = size/2;
    Renderer::getInstance().drawRect(pos.screenToWorld(), size.screenToWorldScale(), Theme::menuBackground);
    for(auto& b : buttons)
        b.draw();
}

std::string Menu::getSelected() {
    for(auto& b : buttons){
        if(b.hasBeenClicked())
            return b.getName();
    }
    return "";
}

Menu::Menu()
    : buttons()
{}

void Menu::addButton(const Button &btn) {
    buttons.emplace_back(btn);
}
