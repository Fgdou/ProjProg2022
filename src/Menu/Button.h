//
// Created by fgdou on 5/20/22.
//

#ifndef PROJPROG2022_BUTTON_H
#define PROJPROG2022_BUTTON_H


#include "../Maths/Vec2.h"
#include "../Entities/DynamicEntity.h"
#include <string>

class Button {
public:
    Button(Vec2& pos, const Vec2& size, const std::string& str, bool clickable);

    void update();
    void draw();

    bool hasBeenClicked();

    const std::string &getName() const;

private:
    bool clicked, hovered, clickable;
    std::string name;
    Vec2 pos;
    Vec2 size;
};


#endif //PROJPROG2022_BUTTON_H
