//
// Created by fgdou on 5/19/22.
//

#ifndef PROJPROG2022_TIMER_H
#define PROJPROG2022_TIMER_H

#include <inttypes.h>
#include <SDL.h>

class Timer
{
private:
public:
    static Timer &getInstance() {}

    // returns the number of ticks since the timer was started
    uint64_t getTicks();

    // returns the number of milliseconds since the last update
    inline uint64_t getDeltaTime()
    {
        return 1000 / 60;
    }

    // returns the number of milliseconds since the timer was started
    uint32_t getMilliseconds();

    void
    update();
};

#endif // PROJPROG2022_TIMER_H
