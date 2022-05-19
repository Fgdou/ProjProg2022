//
// Created by fgdou on 5/19/22.
//

#ifndef PROJPROG2022_RENDERER_H
#define PROJPROG2022_RENDERER_H

#include "Maths/Vec2.h"
#include "Camera.h"
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#define WIN_WIDTH 1280
#define WIN_HEIGHT 720
class Image;

class Renderer
{
private:
    SDL_Window *_win;
    SDL_Renderer *_renderer;
    Camera _camera;
    static std::unique_ptr<Renderer> _instance;

public:
    static Renderer &getInstance();
    SDL_Renderer &getSLDRenderer();
    Renderer();
    ~Renderer();

    void clear();
    void drawCircle(const Vec2 &pos, double size, const SDL_Color &c);
    void drawRect(const Vec2 &center, const Vec2 &scale, const SDL_Color &c);
    void drawImage(const Image &image, const Vec2 &center, const Vec2 &scale, const double rotation);
    void drawText(const std::string &text, const Vec2 &pos, double size, const SDL_Color &c);
    Camera &getCamera();
    static Vec2 getSize() ;
};

#endif // PROJPROG2022_RENDERER_H
