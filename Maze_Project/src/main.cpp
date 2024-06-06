#include "sdl_utils.h"
#include <iostream>
#include <SDL2/SDL.h>

// Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

/**
 * main - Entry point of the program.
 * Initializes SDL, creates a window and renderer, and runs the main loop to
 * handle events and rendering. Implements the raycasting logic to draw walls.
 * Return: 0 on success, non-zero on failure.
 */
int main()
{
    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;

    // Initialize SDL
    if (!initSDL(&window, &renderer, SCREEN_WIDTH, SCREEN_HEIGHT))
    {
        std::cerr << "Failed to initialize SDL\n";
        return 1;
    }

    bool quit = false;
    SDL_Event e;

    // Main loop
    while (!quit)
    {
        // Handle events on queue
        while (SDL_PollEvent(&e) != 0)
        {
            // User requests quit
            if (e.type == SDL_QUIT)
            {
                quit = true;
            }
        }

        // Clear screen
        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(renderer);

        // Rendering logic here (e.g., raycasting and drawing walls)

        // Update screen
        SDL_RenderPresent(renderer);
    }

    // Free resources and close SDL
    closeSDL(window, renderer);

    return 0;
}
