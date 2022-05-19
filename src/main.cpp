//
// Created by fgdou on 5/19/22.
//

#include "Maths/Timer.h"
#include "Renderer.h"

void tps()
{
}
void fps()
{
}

int main(int argc, char **argv)
{

    bool exit = false;
    Timer timer = Timer::getInstance();
    Renderer renderer = Renderer::getInstance();

    uint32_t last_time = timer.getMilliseconds();
    uint32_t time_offset = 0;

    // main loop
    while (!exit)
    {
        uint32_t now = timer.getMilliseconds();
        uint32_t dt = now - last_time;

        while (time_offset < timer.getDeltaTime())
        {
            time_offset += dt;
            now = timer.getMilliseconds();
            dt = now - last_time;
            tps();
        }
        time_offset -= dt;

        fps();
    }
    SDL_Quit();
}
