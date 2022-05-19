//
// Created by fgdou on 5/19/22.
//

#include <iostream>
#include "Maths/Timer.h"
#include "Renderer.h"
#include "Input.h"
#include "World.h"

void tps(const std::shared_ptr<World> &world)
{
    static int cnt = 0;
    cnt++;
    static double lastTime = Timer::getInstance().getSeconds();
    double time = Timer::getInstance().getSeconds();
    if (time - lastTime > 1.0)
    {
        lastTime = time;
        std::cout << cnt << " tps" << std::endl;
        cnt = 0;
    }

    Input::getInstance().update();
    world->update();
}
void fps(const std::shared_ptr<World> &world)
{
    static int cnt = 0;
    cnt++;
    static double lastTime = Timer::getInstance().getSeconds();
    double time = Timer::getInstance().getSeconds();
    if (time - lastTime > 1.0)
    {
        lastTime = time;
        std::cout << cnt << " fps" << std::endl;
        cnt = 0;
    }

    Renderer &renderer = Renderer::getInstance();
    renderer.clear();

    // DRAW CALLS BELLOW
    world->draw();

    Vec2 mouse = Input::getInstance().getMousePos();
    Vec2 pt(-500, 100);

    renderer.drawLine(pt, mouse, {255, 0, 0});
    Room &playerRoom = world->getPlayerRoom();
    Collision col = playerRoom.getCollisionAfterMove(pt, mouse - pt);
    if (col.isColliding)
    {
        // double insideRatio = 1- (col.impact - pt).norm()/(mouse-pt).norm() ;
        renderer.drawRect(col.impact, Vec2(5), {0, 255, 0});
        renderer.drawRect(col.newPos, Vec2(5), {0, 0, 250});
        renderer.drawLine(col.newPos, col.newPos + Vec2(20) *col.newDir.normalize(), {255, 0, 0});
        renderer.drawLine(col.impact, col.impact + col.newDir, {50, 50, 50,255});
    }

    renderer.render();
}

int main(int argc, char **argv)
{
    bool exit = false;
    Timer timer = Timer::getInstance();
    Renderer renderer = Renderer::getInstance();

    double last_time = timer.getSeconds();

    auto world = std::make_shared<World>();

    // main loop
    while (!(Input::getInstance().hasBeenPressedOnce(Input::escape) || Input::getInstance().hasBeenPressedOnce(Input::exit) || world->ended()))
    {
        auto now = timer.getSeconds();
        auto dt = now - last_time;

        if (dt > Timer::getDeltaTime())
        {
            last_time = now;
            tps(world);
        }
        else
        {
            fps(world);
        }

        // std::string err = std::string(SDL_GetError());
        // if (!err.empty())
        //     std::cerr << err << '\n';
    }
    SDL_Quit();
}
