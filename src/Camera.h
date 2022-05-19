//
// Created by fgdou on 5/19/22.
//

#ifndef PROJPROG2022_CAMERA_H
#define PROJPROG2022_CAMERA_H


#include "Maths/Vec2.h"

class Camera {
public:
    void setPos(const Vec2& pos);
    Vec2& getPos();
    double getScale();
};


#endif //PROJPROG2022_CAMERA_H
