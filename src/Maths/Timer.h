//
// Created by fgdou on 5/19/22.
//

#ifndef PROJPROG2022_TIMER_H
#define PROJPROG2022_TIMER_H

#include <inttypes.h>
#include <SDL2/SDL.h>
#include <memory>

#define TARGET_TPS 60;

class Timer
{
private:
    static std::unique_ptr<Timer> ptr;

public:
    Timer();
    void operator=(const Timer&) = delete;

    static Timer &getInstance();

    // returns the number of ticks since the timer was started
    uint64_t getTicks() const;

    // returns the number of milliseconds since the last update
    static inline double getDeltaTime()
    {
        return 1.0 / TARGET_TPS;
    }

    // returns the number of milliseconds since the timer was started
    uint64_t getNanoseconds() const;
    double getSeconds() const;

    void update();

private:
    uint64_t count;
    uint64_t time_started;
};

#endif // PROJPROG2022_TIMER_H
