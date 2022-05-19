//
// Created by fgdou on 5/19/22.
//

#include <memory>
#include "Timer.h"

Timer::Timer()
    : count(0), time_started(clock())
{

}

std::unique_ptr<Timer> ptr;

Timer &Timer::getInstance() {
    if(ptr == nullptr)
        ptr = std::make_unique<Timer>();
    return *ptr;
}

uint64_t Timer::getTicks() const {
    return count;
}

void Timer::update() {
    count++;
}

uint64_t Timer::getNanoseconds() const {
    uint64_t now = clock();

    return (time_started-now);
}

double Timer::getSeconds() const {
    return (double)getNanoseconds()/CLOCKS_PER_SEC;
}
