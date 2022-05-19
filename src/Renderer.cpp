//
// Created by fgdou on 5/19/22.
//

#include "Renderer.h"
#include "Image.h"
#include <stdexcept>
#include <iostream>

std::unique_ptr<Renderer> Renderer::_instance;

Renderer::Renderer() : _camera({0, 0})
{
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        throw std::runtime_error("Failed to init SDL");
    // create the _win and _renderer
    // note that the _renderer is accelerated
    SDL_CreateWindowAndRenderer(WIN_WIDTH, WIN_HEIGHT, SDL_WINDOW_SHOWN, &_win, &_renderer);

    if (_win == nullptr)
        throw std::runtime_error("Failed to create window");
    if (_renderer == nullptr)
        throw std::runtime_error("Failed to create renderer");
    // SDL_WINDOW_FULLSCREEN or SDL_WINDOW_FULLSCREEN_DESKTOP
    if (SDL_SetWindowFullscreen(_win, 0) != 0)
        throw std::runtime_error("Failed to set to fullscreen");
}

Renderer::~Renderer()
{
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_win);
    std::cout << "delete window" << std::endl;
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
    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
    SDL_RenderClear(_renderer);
}

void Renderer::drawCircle(const Vec2 &pos, double size, const SDL_Color &c)
{
    drawRect(pos, {size, size}, c);
}

void Renderer::drawRect(const Vec2 &center, const Vec2 &scale, const SDL_Color &c)
{
    auto centerScreen = center.worldToScreen();
    auto centerScale = scale.worldToScreenScale();
    SDL_Rect rect;
    rect.x = centerScreen.x - scale.x / 2;
    rect.y = centerScreen.y - scale.y / 2;
    rect.w = centerScale.x;
    rect.h = centerScale.y;
    SDL_SetRenderDrawColor(_renderer, c.r, c.g, c.b, c.a);
    SDL_RenderFillRect(_renderer, &rect);
}

void Renderer::drawImage(const Image &image, const Vec2 &center, const Vec2 &scale, const double rotation)
{
    auto centerScreen = center.worldToScreen();
    auto centerScale = scale.worldToScreenScale();
    SDL_Rect rect;
    rect.x = centerScreen.x - scale.x / 2;
    rect.y = centerScreen.y - scale.y / 2;
    rect.w = centerScale.x;
    rect.h = centerScale.y;
    SDL_Texture *texture = image.get();
    SDL_RenderCopyEx(_renderer, texture, nullptr, &rect, rotation, nullptr, SDL_FLIP_NONE);
}

void Renderer::drawText(const std::string &text, const Vec2 &pos, double size, const SDL_Color &c)
{
    auto posScreen = pos.worldToScreen();

    SDL_Color color = {c.r, c.g, c.b, c.a};
    TTF_Font *font = TTF_OpenFont("assets/fonts/JoefinSans.ttf", size);
    SDL_Surface *surface = TTF_RenderText_Solid(font, text.c_str(), color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(_renderer, surface);
    SDL_Rect rect;
    rect.x = posScreen.x;
    rect.y = posScreen.y;
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

Vec2 Renderer::getSize()
{
    return {WIN_WIDTH, WIN_HEIGHT};
}

void Renderer::render()
{
    SDL_RenderPresent(_renderer);
}
