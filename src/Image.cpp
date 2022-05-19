//
// Created by fgdou on 5/19/22.
//

#include "Image.h"

Image::Image(const std::string &path)
{
  SDL_Renderer &sdl_renderer = Renderer::getInstance().getSLDRenderer();

  _texture = IMG_LoadTexture(&sdl_renderer, path.c_str());
}

Image::~Image()
{
  SDL_DestroyTexture(_texture);
}

SDL_Texture *Image::get() const
{
  return _texture;
}