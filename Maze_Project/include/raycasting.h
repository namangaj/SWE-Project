#ifndef RAYCASTING_H
#define RAYCASTING_H

#include <SDL2/SDL.h>

#define MAP_WIDTH 24
#define MAP_HEIGHT 24

/**
 * renderScene - Renders the scene using raycasting.
 * @renderer: Pointer to the SDL_Renderer.
 * @screenWidth: Width of the screen.
 * @screenHeight: Height of the screen.
 * @posX: Player's x position.
 * @posY: Player's y position.
 * @dirX: Player's x direction.
 * @dirY: Player's y direction.
 * @planeX: Camera plane x.
 * @planeY: Camera plane y.
 * @worldMap: 2D array representing the map.
 */
void renderScene(SDL_Renderer *renderer, int screenWidth, int screenHeight,
double posX, double posY, double dirX, double dirY,
double planeX, double planeY, int worldMap[MAP_WIDTH][MAP_HEIGHT]);

#endif /* RAYCASTING_H */
