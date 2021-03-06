//
// Created by fgdou on 5/19/22.
//

#include "Animation.h"
#include "../Maths/Timer.h"

bool Animation::running() const {
    return time < duration;
}
void Animation::update() {
    if(time >= duration)
        time = duration;
    else
        time += Timer::getDeltaTime();
}

Animation::Animation(double duration)
    : duration(duration), time(0)
{}

double Animation::getTime() const {
    return time;
}

double Animation::getDuration() const {
    return duration;
}

double Animation::getAvancement() const {
    double t = time/duration;
    return (t*t)/(2.0*(t*t-t)+1.0);
}
