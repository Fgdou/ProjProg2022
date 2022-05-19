//
// Created by fgdou on 5/19/22.
//

#ifndef PROJPROG2022_TIMER_H
#define PROJPROG2022_TIMER_H

#include <inttypes.h>

class Timer {
public:
    static Timer& getInstance(){}

    virtual uint64_t getTicks() = 0;
    inline double getDeltaTime(){
        return 1.0/60;
    }
};


#endif //PROJPROG2022_TIMER_H
