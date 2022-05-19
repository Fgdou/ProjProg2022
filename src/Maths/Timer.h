//
// Created by fgdou on 5/19/22.
//

#ifndef PROJPROG2022_TIMER_H
#define PROJPROG2022_TIMER_H

#include <inttypes.h>

class Timer {
public:
    static Timer& getInstance(){}

    uint64_t getTicks();
    inline double getDeltaTime(){
        return 1.0/60;
    }

    void update();
};


#endif //PROJPROG2022_TIMER_H
