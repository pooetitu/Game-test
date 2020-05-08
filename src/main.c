#include <stdlib.h>
#include <stdio.h>

#include <SDL.h>

#include "main.h"

struct Player {
    int x;
    int y;
    int size;
    Uint8 r;
    Uint8 g;
    Uint8 b;
};

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
    int w;
    int h;
    SDL_GetWindowSize(window, &w, &h);

    printf("%d %d", w, h);
    Player p1 = {10, 10, 10, 255, 0, 0};
    Player p2 = {w-10, 10, 10, 0, 0, 255};
    Uint8 r = 0, g = 0, b = 0;
    while (1) {
        SDL_SetRenderDrawColor(renderer, r, g, b, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(renderer);
        p1.x++;
        p1.y++;


        SDL_SetRenderDrawColor(renderer, p1.r, p1.g, p1.b, SDL_ALPHA_OPAQUE);
        drawCircle(p1.size, p1.x, p1.y, renderer);

        SDL_SetRenderDrawColor(renderer, p2.r, p2.g, p2.b, SDL_ALPHA_OPAQUE);
        drawCircle(p2.size, p2.x, p2.y, renderer);
        SDL_RenderPresent(renderer);
    }
	
    return 0;
}


void drawCircle(int radius, int x, int y, SDL_Renderer *renderer) {
    for (float i = 0.00f; i < 360.00f; i += 0.01f) {
        float angle = i * M_PI / 180;
        SDL_RenderDrawPoint(renderer, radius * sin(angle) + x, radius * cos(angle) + y);
    }
}
