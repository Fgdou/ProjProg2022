
#ifndef PROJPROG2022_THEME_H
#define PROJPROG2022_THEME_H

#include <SDL2/SDL.h>

namespace Theme {
    const SDL_Color background = {68, 68, 68};
    const SDL_Color wall = {23, 23, 23};
    const SDL_Color door = {20, 40, 49};
    const SDL_Color text = {250, 250, 250};
    const SDL_Color player = {237, 237, 237};
    const SDL_Color lifeBarFull = {255, 0, 0, 255};
    const SDL_Color lifeBarBackground = {100, 0, 0, 255};
    const SDL_Color enemy = {218, 0, 55};
    const SDL_Color button = {0,0,0,255};
    const SDL_Color button_hovered = {20,20,20,255};
    const SDL_Color menuBackground = {0,0,0,100};
}
#endif