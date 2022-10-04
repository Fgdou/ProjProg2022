//
// Created by fgdou on 5/19/22.
//

#include "Renderer.h"
#include "Image.h"
#include <stdexcept>
#include <iostream>
#include "Theme.h"

std::unique_ptr<Renderer> Renderer::_instance;

Renderer::Renderer() : _camera({0, 0}), funMeter(0)
{
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        throw std::runtime_error("Failed to init SDL");
    // create the _win and _renderer
    // note that the _renderer is accelerated
    SDL_CreateWindowAndRenderer(WIN_WIDTH, WIN_HEIGHT, SDL_WINDOW_SHOWN | 0, &_win, &_renderer);

    if (_win == nullptr)
        throw std::runtime_error("Failed to create window");
    if (_renderer == nullptr)
        throw std::runtime_error("Failed to create renderer");
    // SDL_WINDOW_FULLSCREEN or SDL_WINDOW_FULLSCREEN_DESKTOP
    if (SDL_SetWindowFullscreen(_win, 0) != 0)
        throw std::runtime_error("Failed to set to fullscreen");

    TTF_Init();

    SDL_SetRenderDrawBlendMode(_renderer, SDL_BLENDMODE_BLEND);
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



/**
 * Code fetch from https://gist.github.com/Gumichan01/332c26f6197a432db91cc4327fcabb1c
 * @param renderer
 * @param x
 * @param y
 * @param radius
 * @return
 */
int
SDL_RenderFillCircle(SDL_Renderer * renderer, int x, int y, int radius)
{
    int offsetx, offsety, d;
    int status;

//    CHECK_RENDERER_MAGIC(renderer, -1);

    offsetx = 0;
    offsety = radius;
    d = radius -1;
    status = 0;

    while (offsety >= offsetx) {

        status += SDL_RenderDrawLine(renderer, x - offsety, y + offsetx,
                                     x + offsety, y + offsetx);
        status += SDL_RenderDrawLine(renderer, x - offsetx, y + offsety,
                                     x + offsetx, y + offsety);
        status += SDL_RenderDrawLine(renderer, x - offsetx, y - offsety,
                                     x + offsetx, y - offsety);
        status += SDL_RenderDrawLine(renderer, x - offsety, y - offsetx,
                                     x + offsety, y - offsetx);

        if (status < 0) {
            status = -1;
            break;
        }

        if (d >= 2*offsetx) {
            d -= 2*offsetx + 1;
            offsetx +=1;
        }
        else if (d < 2 * (radius - offsety)) {
            d += 2 * offsety - 1;
            offsety -= 1;
        }
        else {
            d += 2 * (offsety - offsetx - 1);
            offsety -= 1;
            offsetx += 1;
        }
    }

    return status;
}

void Renderer::clear()
{
    SDL_SetRenderDrawColor(_renderer,Theme::background.r,Theme::background.g,Theme::background.b,Theme::background.a);
    SDL_RenderClear(_renderer);
}

void Renderer::drawCircle(const Vec2 &pos, double size, const SDL_Color &c)
{
//    drawRect(pos, {size, size}, c);
    auto p = pos.worldToScreen();
    SDL_SetRenderDrawColor(_renderer, c.r, c.g, c.b, c.a);
    SDL_RenderFillCircle(_renderer, p.x, p.y, size);
}

void Renderer::drawRect(const Vec2 &center, const Vec2 &scale, const SDL_Color &c)
{
    auto centerScreen = center.worldToScreen();
    auto centerScale = scale.worldToScreenScale();
    SDL_Rect rect;
    rect.x = centerScreen.x - centerScale.x / 2;
    rect.y = centerScreen.y - centerScale.y / 2;
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
    rect.x = centerScreen.x - centerScale.x / 2;
    rect.y = centerScreen.y - centerScale.y / 2;
    rect.w = centerScale.x;
    rect.h = centerScale.y;
    SDL_Texture *texture = image.get();
    SDL_RenderCopyEx(_renderer, texture, nullptr, &rect, rotation, nullptr, SDL_FLIP_NONE);
}

void Renderer::drawText(const std::string &text, const Vec2 &pos, double size, const SDL_Color &c)
{
    auto posScreen = pos.worldToScreen();
    SDL_Color color = {c.r, c.g, c.b, c.a};
    TTF_Font *font = TTF_OpenFont("../assets/fonts/roboto/Roboto-Bold.ttf", size);
    if (font == nullptr)
    {
        throw std::runtime_error("Failed to open font");
    }
    SDL_Surface *surface = TTF_RenderText_Solid(font, text.c_str(), color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(_renderer, surface);
    SDL_Rect rect;
    rect.x = posScreen.x-surface->w/2;
    rect.y = posScreen.y-surface->h/2;
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

SDL_Window *Renderer::getWin() const {
    return _win;
}

void Renderer::setWindowTitle(const std::string &name) {
    SDL_SetWindowTitle(_win, name.c_str());
}
