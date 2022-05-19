//
// Created by fgdou on 5/19/22.
//

#ifndef PROJPROG2022_RENDERER_H
#define PROJPROG2022_RENDERER_H


#include <string>
#include "Maths/Vec2.h"

#include "SDL2/SDL.h"

class Renderer {
public:
//    static Renderer& getInstance(){
//        return Renderer();
//    }

    virtual void drawCircle(const Vec2& pos, double size, const SDL_Color& c) = 0;
    virtual void drawRect(const Vec2& center, const Vec2& halfSize, const SDL_Color& c) = 0;
    virtual void drawImage(const std::string& path, const Vec2& center, const Vec2& halfSize) = 0;
    virtual void drawText(const std::string& text, const Vec2& p1, double size) = 0;
    virtual void clear() = 0;

    virtual const Vec2& getSize() = 0;

};


#endif //PROJPROG2022_RENDERER_H
