
#ifndef PROJPROG2022_THEME_H
#define PROJPROG2022_THEME_H

#include <SDL2/SDL.h>

namespace Theme {
    const SDL_Color background = {68, 68, 68, 255};
    const SDL_Color background_high = {168, 168, 168, 255};
    const SDL_Color background_low = {200, 68, 68, 255};
    const SDL_Color wall = {23, 23, 23, 255};
    const SDL_Color wall_high = {123, 123, 123, 255};
    const SDL_Color wall_low = {200, 23, 23, 255};
    const SDL_Color door = {20, 40, 49, 255};
    const SDL_Color text = {250, 250, 250, 255};
    const SDL_Color player = {237, 237, 237, 255};
    const SDL_Color lifeBarFull = {255, 0, 0, 255};
    const SDL_Color progressCooldown = {226,135,67, 255};
    const SDL_Color lifeBarBackground = {100, 0, 0, 255};
    const SDL_Color enemy = {218, 0, 55, 255};
    const SDL_Color button = {0,0,0,255};
    const SDL_Color button_hovered = {20,20,20,255};
    const SDL_Color menuBackground = {0,0,0,100};
}
#endif