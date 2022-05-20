//
// Created by fgdou on 5/20/22.
//

#ifndef PROJPROG2022_MENU_H
#define PROJPROG2022_MENU_H

#include <string>
#include <vector>
#include "Button.h"


class Menu {
public:
    Menu();
    ~Menu() = default;

    void update();
    void draw();

    std::string getSelected();

    void addButton(const Button& btn);

private:
    std::vector<Button> buttons;
};


#endif //PROJPROG2022_MENU_H
