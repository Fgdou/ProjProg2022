//
// Created by fgdou on 5/20/22.
//

#include "StartMenu.h"
#include "../Renderer.h"

StartMenu::StartMenu() {
    auto ssize = Renderer::getSize();
    auto size = Vec2{300, 100};
    auto pos = ssize/2 - Vec2{0, 60};

    addButton(Button{
        pos, size, "Play", true
    });

    pos += {0, 120};
    addButton(Button{
            pos, size, "Quit", true
    });
}
