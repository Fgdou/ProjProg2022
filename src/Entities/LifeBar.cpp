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
    Vec2 winSize = Renderer::getSize();
    double height = 10;
    Vec2 size(winSize.x, height);
    Vec2 pos = winSize - Vec2{winSize.x/2, height/2};

    Renderer& r = Renderer::getInstance();
    r.drawRect(pos.screenToWorld(), size.screenToWorldScale(), Theme::lifeBarBackground);

    auto newpos = pos;
    auto newsize = size;
    newpos.x -= size.x/2*(1-percent);
    newsize.x *= percent;
    r.drawRect(newpos.screenToWorld(), newsize.screenToWorldScale(), Theme::lifeBarFull);
}
