//
// Created by fgdou on 5/19/22.
//

#ifndef PROJPROG2022_IMAGE_H
#define PROJPROG2022_IMAGE_H

#include "Maths/Vec2.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Renderer.h"

class Image
{
private:
    SDL_Texture *_texture;

public:
    // load the image
    Image(const std::string &path);

    SDL_Texture *get() const;

    // unload the image
    ~Image();
};

#endif // PROJPROG2022_IMAGE_H
