//
// Created by fgdou on 5/19/22.
//

#include "Timer.h"

Timer::Timer()
    : count(0), time_started(clock())
{
}

std::unique_ptr<Timer> Timer::ptr;

Timer &Timer::getInstance()
{
    if (ptr == nullptr)
        ptr = std::make_unique<Timer>();
    return *ptr;
}

uint64_t Timer::getTicks() const
{
    return count;
}

void Timer::update()
{
    count++;
}

double Timer::getSeconds() const
{
    return (double)SDL_GetTicks64() / 1000;
}
