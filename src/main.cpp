//
// Created by fgdou on 5/19/22.
//

#include <iostream>
#include "Maths/Timer.h"
#include "Renderer.h"
#include "Input.h"

void tps()
{
    static double time = Timer::getInstance().getSeconds();
    static double lastTime = Timer::getInstance().getSeconds();
    double dt = lastTime - time;
    std::cout << (int)(1/dt) << " tps" << std::endl;
    lastTime = time;

    Input::getInstance().update();
}
void fps()
{
    static double time = Timer::getInstance().getSeconds();
    static double lastTime = Timer::getInstance().getSeconds();
    double dt = lastTime - time;
    std::cout << (int)(1/dt) << " fps" << std::endl;
    lastTime = time;
}

int main(int argc, char **argv)
{
    bool exit = false;
    Timer timer = Timer::getInstance();
    Renderer renderer = Renderer::getInstance();

    double last_time = timer.getSeconds();
    double time_offset = 0;

    // main loop
    while (!Input::getInstance().hasBeenPressedOnce(Input::escape)){
        auto now = timer.getSeconds();
        auto dt = now - last_time;

        while (time_offset < Timer::getDeltaTime())
        {
            time_offset += dt;
            now = timer.getSeconds();
            dt = now - last_time;
            tps();
        }
        time_offset -= dt;

        fps();
    }
    SDL_Quit();
}
