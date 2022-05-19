//
// Created by fgdou on 5/19/22.
//

#include <iostream>
#include "Maths/Timer.h"
#include "Renderer.h"
#include "Input.h"

void tps()
{
    static int cnt = 0;
    cnt++;
    static double lastTime = Timer::getInstance().getSeconds();
    double time = Timer::getInstance().getSeconds();
    if(time - lastTime > 1.0){
        lastTime = time;
        std::cout << cnt << " tps" << std::endl;
        cnt = 0;
    }

    Input::getInstance().update();
}
void fps()
{
    static int cnt = 0;
    cnt++;
    static double lastTime = Timer::getInstance().getSeconds();
    double time = Timer::getInstance().getSeconds();
    if(time - lastTime > 1.0){
        lastTime = time;
        std::cout << cnt << " fps" << std::endl;
        cnt = 0;
    }

    Renderer renderer = Renderer::getInstance();
    renderer.clear();

    //  DRAW CALLS BELLOW

    SDL_RenderPresent(&renderer.getSLDRenderer());
}

int main(int argc, char **argv)
{
    bool exit = false;
    Timer timer = Timer::getInstance();
    Renderer renderer = Renderer::getInstance();

    double last_time = timer.getSeconds();

    // main loop
    while (!Input::getInstance().hasBeenPressedOnce(Input::escape))
    {
        auto now = timer.getSeconds();
        auto dt = now - last_time;

        if (dt > Timer::getDeltaTime())
        {
            last_time = now;
            tps();
        }else{
            fps();
        }

    }
    SDL_Quit();
}
