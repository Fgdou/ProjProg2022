//
// Created by fgdou on 5/19/22.
//

#include "LifeBar.h"
#include "../Theme.h"
#include "../Maths/Vec2.h"
#include "Player.h"

LifeBar::LifeBar(Player &p)
    : p(p)
{}

void LifeBar::draw() {
    double percent = p.getLife()/p.getLifeMax();
    Vec2 size(200, 20);
    Vec2 pos = Renderer::getSize() - Vec2{10, 10};

    Renderer& r = Renderer::getInstance();
    r.drawRect((pos-size/2).screenToWorld(), size.screenToWorldScale(), Theme::lifeBarBackground);
}
