#include "sdl_utils.h"

/**
 * initSDL - Initializes SDL, creates a window and renderer.
 * @window: Pointer to the SDL_Window pointer.
 * @renderer: Pointer to the SDL_Renderer pointer.
 * @screenWidth: Width of the screen.
 * @screenHeight: Height of the screen.
 *
 * Return: true if successful, false otherwise.
 */
bool initSDL(SDL_Window **window, SDL_Renderer **renderer, int screenWidth,
             int screenHeight)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        SDL_Log("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    *window = SDL_CreateWindow("Maze Project", SDL_WINDOWPOS_UNDEFINED,
                               SDL_WINDOWPOS_UNDEFINED, screenWidth,
                               screenHeight, SDL_WINDOW_SHOWN);
    if (*window == nullptr)
    {
        SDL_Log("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    *renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED);
    if (*renderer == nullptr)
    {
        SDL_Log("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    return true;
}

/**
 * closeSDL - Destroys the SDL window and renderer, and quits SDL.
 * @window: Pointer to the SDL_Window.
 * @renderer: Pointer to the SDL_Renderer.
 *
 * This function releases all the resources allocated by SDL, including the
 * window and renderer, and then quits SDL subsystems. It should be called
 * before the program exits to ensure that all resources are properly
 * cleaned up.
 */
void closeSDL(SDL_Window *window, SDL_Renderer *renderer)
{
    if (renderer)
    {
        SDL_DestroyRenderer(renderer);
    }
    if (window)
    {
        SDL_DestroyWindow(window);
    }
    SDL_Quit();
}
