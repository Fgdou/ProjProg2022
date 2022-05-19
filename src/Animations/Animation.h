//
// Created by fgdou on 5/19/22.
//

#ifndef PROJPROG2022_ANIMATION_H
#define PROJPROG2022_ANIMATION_H


class Animation {
public:
    Animation(double duration);
    bool running() const;

    virtual void update();
    virtual void draw() = 0;

    double getDuration() const;
    double getTime() const;
    double getAvancement() const;

private:
    double duration;
    double time;
};


#endif //PROJPROG2022_ANIMATION_H
