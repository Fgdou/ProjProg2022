//
// Created by fgdou on 5/19/22.
//

#ifndef PROJPROG2022_CAMERA_H
#define PROJPROG2022_CAMERA_H


#include "Maths/Vec2.h"

class Camera {
public:
    Camera(const Vec2& pos);

    void setPos(const Vec2& pos);
    const Vec2& getPos() const;
    double getScale() const;
    void setScale(double v);

private:
    Vec2 pos;
    double scale;
};


#endif //PROJPROG2022_CAMERA_H
