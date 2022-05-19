//
// Created by guill on 19/05/2022.
//

#ifndef PROJPROG2022_WALL_H
#define PROJPROG2022_WALL_H

#include "../Entities/Entity.h"
#include <SDL2/SDL.h>
#include "../Image.h"

class Wall : public Entity
{
protected:
    Vec2 _size;
    bool _isEnabled;
    SDL_Color _color;
    std::shared_ptr<Image> _texture;

public:
    // pos : top left corner position
    // size : scale of the wall (width, height)
    Wall(Vec2 &pos, Vec2 &size);
    ~Wall() = default;

    Vec2 getSize() const;
    void setColor(SDL_Color &c);
    void setTexture(std::shared_ptr<Image> &texture);
    void toggle();
    void disable();
    void enable();
    void draw();
    bool isEnabled();
};

#endif // PROJPROG2022_WALL_H
