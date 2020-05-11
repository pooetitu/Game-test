#include <stdlib.h>
#include <stdio.h>

#include <SDL.h>

#include "player.h"
#include "client.h"

int ClientInit(SDL_Renderer** renderer, SDL_Window** window) {
    if (SDL_Init(SDL_INIT_VIDEO)) {
        printf("SDL initialisation error %s", SDL_GetError());
        return EXIT_FAILURE;
    }
    *window = SDL_CreateWindow("Game screen", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_RESIZABLE);
    if (*window == NULL) {
        printf("Window initialisation error  %s", SDL_GetError());
        return EXIT_FAILURE;
    }
    *renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED);
    if (*renderer == NULL) {
        printf("Renderer initialisation error  %s", SDL_GetError());
        return EXIT_FAILURE;
    }
    SDL_SetWindowResizable(*window, SDL_FALSE);
    return 0;
}

void ClientRun(SDL_Renderer* renderer, SDL_Window* window) {
    int h = WINDOW_HEIGHT;
    int w = WINDOW_WIDTH;
    PlayerData p1 = { w - 15, h - 15, 15, 5,0, 0, 0, 255, SDL_SCANCODE_RCTRL, SDL_SCANCODE_UP, SDL_SCANCODE_DOWN, SDL_SCANCODE_LEFT, SDL_SCANCODE_RIGHT,NULL };
    PlayerData p2 = { 15, h - 15, 15, 5, 0,255, 0, 0, SDL_SCANCODE_SPACE, SDL_SCANCODE_W,SDL_SCANCODE_S,SDL_SCANCODE_A,SDL_SCANCODE_D,NULL };

    Uint8 r = 0, g = 0, b = 0;
    SDL_Event event;
    int quit = 0;

    while (!quit) {
        SDL_Delay(50);
        SDL_SetRenderDrawColor(renderer, r, g, b, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(renderer);

        UpdatePlayer(&p1, renderer);
        UpdatePlayer(&p2, renderer);


        SDL_RenderPresent(renderer);

        if (!SDL_PollEvent(&event)) continue;   
        switch (event.type) {
        case SDL_QUIT:
            quit = SDL_TRUE;
            break;
        }
    }
}
