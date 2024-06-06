#ifndef SDL_UTILS_H
#define SDL_UTILS_H

#include <SDL2/SDL.h>
#include <iostream>

bool initSDL(SDL_Window * *window, SDL_Renderer * *renderer, int screenWidth,
int screenHeight);
void closeSDL(SDL_Window *window, SDL_Renderer *renderer);

#endif /* SDL_UTILS_H*/
