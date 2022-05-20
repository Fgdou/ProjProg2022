//
// Created by fgdou on 5/20/22.
//

#include "EndMenu.h"
#include "../Renderer.h"

EndMenu::EndMenu(bool win): Menu(2.0) {
    auto ssize = Renderer::getSize();
    auto size = Vec2{300, 100};
    auto pos = ssize/2 - Vec2{0, 160};

    std::string str = (win) ? "You win !" : "Your are dead !";

    addButton(Button{
            pos, size, str, false
    });

    pos += {0, 120};
    addButton(Button{
            pos, size, "Restart", true
    });

    pos += {0, 120};
    addButton(Button{
            pos, size, "Quit", true
    });
}
