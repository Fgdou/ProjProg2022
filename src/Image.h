//
// Created by fgdou on 5/19/22.
//

#ifndef PROJPROG2022_IMAGE_H
#define PROJPROG2022_IMAGE_H


#include "Maths/Vec2.h"

class Image {
public:
    virtual void draw(const Vec2& center, const Vec2& halfSize) = 0;
};


#endif //PROJPROG2022_IMAGE_H
