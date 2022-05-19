//
// Created by fgdou on 5/19/22.
//

#include "Renderer.h"
#include "Image.h"

std::unique_ptr<Renderer> Renderer::_instance;

Renderer::Renderer() : _win(nullptr), _renderer(nullptr), _camera({0, 0})
{
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
    return;
  // create the _win and _renderer
  // note that the _renderer is accelerated
  _win = SDL_CreateWindow("LE JEU", 100, 100, WIN_WIDTH, WIN_HEIGHT, 0);
  _renderer = SDL_CreateRenderer(_win, -1, SDL_RENDERER_ACCELERATED);
}

Renderer::~Renderer()
{
  SDL_DestroyRenderer(_renderer);
  SDL_DestroyWindow(_win);
}

Renderer &Renderer::getInstance()
{
  if (_instance == nullptr)
  {
    _instance = std::make_unique<Renderer>();
  }
  return *_instance;
}

SDL_Renderer &Renderer::getSLDRenderer()
{
  return *_renderer;
}

void Renderer::clear()
{
  SDL_RenderClear(_renderer);
}

void Renderer::drawCircle(const Vec2 &pos, double size, const SDL_Color &c)
{
  drawRect(pos, {size, size}, c);
}

void Renderer::drawRect(const Vec2 &center, const Vec2 &scale, const SDL_Color &c)
{
  SDL_Rect rect;
  rect.x = center.x - scale.x / 2;
  rect.y = center.y - scale.y / 2;
  rect.w = scale.x;
  rect.h = scale.y;
  SDL_SetRenderDrawColor(_renderer, c.r, c.g, c.b, c.a);
  SDL_RenderFillRect(_renderer, &rect);
}

void Renderer::drawImage(const Image &image, const Vec2 &center, const Vec2 &scale, const double rotation)
{
  SDL_Rect rect;
  rect.x = center.x - scale.x / 2;
  rect.y = center.y - scale.y / 2;
  rect.w = scale.x;
  rect.h = scale.y;
  SDL_Texture *texture = image.get();
  SDL_RenderCopyEx(_renderer, texture, nullptr, &rect, rotation, nullptr, SDL_FLIP_NONE);
}

void Renderer::drawText(const std::string &text, const Vec2 &pos, double size, const SDL_Color &c)
{
  SDL_Color color = {c.r, c.g, c.b, c.a};
  TTF_Font *font = TTF_OpenFont("assets/fonts/JoefinSans.ttf", size);
  SDL_Surface *surface = TTF_RenderText_Solid(font, text.c_str(), color);
  SDL_Texture *texture = SDL_CreateTextureFromSurface(_renderer, surface);
  SDL_Rect rect;
  rect.x = pos.x;
  rect.y = pos.y;
  rect.w = surface->w;
  rect.h = surface->h;
  SDL_RenderCopy(_renderer, texture, nullptr, &rect);
  SDL_DestroyTexture(texture);
  SDL_FreeSurface(surface);
  TTF_CloseFont(font);
}

Camera &Renderer::getCamera()
{
  return _camera;
}

Vec2 Renderer::getSize() {
  return {WIN_WIDTH, WIN_HEIGHT};
}