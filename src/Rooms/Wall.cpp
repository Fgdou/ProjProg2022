//
// Created by guill on 19/05/2022.
//

#include "Wall.h"

Wall::Wall(Vec2 &pos, Vec2 &size) : Entity(pos), _size(size), _isEnabled(true), _color({15, 15, 15, 255}), _texture(nullptr)
{
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
  Renderer::getInstance().drawRect(pos, _size, _color);
}