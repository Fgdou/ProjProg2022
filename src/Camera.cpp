//
// Created by fgdou on 5/19/22.
//

#include "Camera.h"

Camera::Camera(const Vec2 &pos)
    : scale(1), pos(pos)
{

}

void Camera::setPos(const Vec2 &_pos) {
    pos = _pos;
}

const Vec2 &Camera::getPos() const {
    return pos;
}

double Camera::getScale() const {
    return scale;
}

void Camera::setScale(double v) {
    scale = v;
}
