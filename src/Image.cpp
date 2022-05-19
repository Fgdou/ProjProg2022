//
// Created by fgdou on 5/19/22.
//

#include <stdexcept>
#include "Image.h"

Image::Image(const std::string &path) : _texture(nullptr), path(path)
{
  SDL_Renderer &sdl_renderer = Renderer::getInstance().getSLDRenderer();

  _texture = IMG_LoadTexture(&sdl_renderer, path.c_str());

  if(_texture == nullptr)
      throw std::runtime_error("Failed to open image");
}

Image::~Image()
{
  SDL_DestroyTexture(_texture);
}

SDL_Texture *Image::get() const
{
  return _texture;
}

Image::Image(const Image &copy)
    : _texture(nullptr), path(copy.path)
{
    SDL_Renderer &sdl_renderer = Renderer::getInstance().getSLDRenderer();
    _texture = IMG_LoadTexture(&sdl_renderer, path.c_str());
}

Image &Image::operator=(const Image &copy) {
    SDL_DestroyTexture(_texture);

    _texture = nullptr;
    path = copy.path;

    SDL_Renderer &sdl_renderer = Renderer::getInstance().getSLDRenderer();
    _texture = IMG_LoadTexture(&sdl_renderer, path.c_str());

    return *this;
}
