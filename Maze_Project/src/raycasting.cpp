#include "raycasting.h"

void renderScene(SDL_Renderer *renderer, int screenWidth, int screenHeight,
                 double posX, double posY, double dirX, double dirY,
                 double planeX, double planeY, int worldMap[MAP_WIDTH][MAP_HEIGHT])
{
    int x;
    for (x = 0; x < screenWidth; ++x)
    {
        double cameraX = 2 * x / (double)screenWidth - 1;
        double rayDirX = dirX + planeX * cameraX;
        double rayDirY = dirY + planeY * cameraX;

        int mapX = (int)posX;
        int mapY = (int)posY;

        double sideDistX;
        double sideDistY;

        double deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
        double deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);
        double perpWallDist;

        int stepX;
        int stepY;

        int hit = 0;
        int side;

        if (rayDirX < 0)
        {
            stepX = -1;
            sideDistX = (posX - mapX) * deltaDistX;
        }
        else
        {
            stepX = 1;
            sideDistX = (mapX + 1.0 - posX) * deltaDistX;
        }
        if (rayDirY < 0)
        {
            stepY = -1;
            sideDistY = (posY - mapY) * deltaDistY;
        }
        else
        {
            stepY = 1;
            sideDistY = (mapY + 1.0 - posY) * deltaDistY;
        }

        while (hit == 0)
        {
            if (sideDistX < sideDistY)
            {
                sideDistX += deltaDistX;
                mapX += stepX;
                side = 0;
            }
            else
            {
                sideDistY += deltaDistY;
                mapY += stepY;
                side = 1;
            }
            if (worldMap[mapX][mapY] > 0)
            {
                hit = 1;
            }
        }

        if (side == 0)
        {
            perpWallDist = (mapX - posX + (1 - stepX) / 2) / rayDirX;
        }
        else
        {
            perpWallDist = (mapY - posY + (1 - stepY) / 2) / rayDirY;
        }

        int lineHeight = (int)(screenHeight / perpWallDist);

        int drawStart = -lineHeight / 2 + screenHeight / 2;
        if (drawStart < 0)
        {
            drawStart = 0;
        }
        int drawEnd = lineHeight / 2 + screenHeight / 2;
        if (drawEnd >= screenHeight)
        {
            drawEnd = screenHeight - 1;
        }

        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        if (side == 1)
        {
            SDL_SetRenderDrawColor(renderer, 127, 0, 0, 255);
        }
        SDL_RenderDrawLine(renderer, x, drawStart, x, drawEnd);
    }
}
