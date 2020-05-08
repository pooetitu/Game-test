#include <stdlib.h>
#include <stdio.h>

#include <SDL.h>

#include "main.h"

int main(int argv, char* argc[]) {
    
    if (SDL_Init(SDL_INIT_VIDEO))
    {
        printf("SDL initialisation error %s", SDL_GetError());
        return EXIT_FAILURE;
    }
    SDL_Renderer* renderer = NULL;
    SDL_Window* window = NULL;
    window = SDL_CreateWindow("Game screen", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_RESIZABLE);
    if (window == NULL)
    {
        printf("Window initialisation error  %s", SDL_GetError());
        return EXIT_FAILURE;
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL)
    {
        printf("Renderer initialisation error  %s", SDL_GetError());
        return EXIT_FAILURE;
    }

    Uint8 r=255, g=0, b=255;
    SDL_SetRenderDrawColor(renderer,r,g,b,SDL_ALPHA_OPAQUE);
    drawCircle(150, 0, 0, renderer);
    SDL_RenderPresent(renderer);
    SDL_Delay(3000);
	
    return 0;
}

void drawCircle(int radius, int x, int y, SDL_Renderer *renderer) {
    for (float i = 0.00f; i < 360.00f; i += 0.01f) {
        float angle = i * M_PI / 180;
        SDL_RenderDrawPoint(renderer, radius * sin(angle) + x + radius, radius * cos(angle) + y + radius);
    }
}
