//
// Created by guill on 19/05/2022.
//

#include "Wall.h"
#include "../Theme.h"

Wall::Wall(Vec2 &pos, Vec2 &size) : Entity(pos), _size(size), _isEnabled(true), _color(Theme::wall), _texture(nullptr)
{
}
Vec2 Wall::getSize() const
{
    return _size;
}

void Wall::setColor(SDL_Color &c)
{
    _color = c;
}

void Wall::setTexture(std::shared_ptr<Image> &texture)
{
    _texture = texture;
}

void Wall::toggle()
{
    _isEnabled = !_isEnabled;
}

void Wall::disable()
{
    _isEnabled = false;
}

void Wall::enable()
{
    _isEnabled = true;
}

bool Wall::isEnabled()
{
    return _isEnabled;
}

void Wall::draw()
{
    if(!_isEnabled)
        return;
    Vec2 posToDraw = (position + _size/2);
    if (_texture != nullptr)
    {
        Renderer::getInstance().drawImage(*_texture, posToDraw, _size, 0);
    }
    else
    {
        Renderer::getInstance().drawRect(posToDraw, _size, _color);
    }
}