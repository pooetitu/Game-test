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
    SDL_Scancode up;
    SDL_Scancode down;
    SDL_Scancode left;
    SDL_Scancode right;
};


int main(int argv, char* argc[]) {
    int h = WINDOW_HEIGHT;
    int w = WINDOW_WIDTH;
    
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

    SDL_SetWindowResizable(window, SDL_FALSE);



    printf("%d %d", w, h);
    Player p1 = {10, h-10, 10, 255, 0, 0,SDL_SCANCODE_UP,SDL_SCANCODE_DOWN,SDL_SCANCODE_LEFT,SDL_SCANCODE_RIGHT};
    Player p2 = {w-10, h-10, 10, 0, 0, 255,SDL_SCANCODE_Z,SDL_SCANCODE_S,SDL_SCANCODE_Q,SDL_SCANCODE_D};
    Uint8 r=0, g=0, b=0;
    SDL_Event event;
    int quit = 0;


    while (!quit) {
        SDL_Delay(10);
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
    return 0;
}

void UpdatePlayer(Player* player,SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, player->r, player->g, player->b, SDL_ALPHA_OPAQUE);
    DrawCircle(player->size, player->x, player->y, renderer);
    UpdatePlayerPosition(player);
}

void UpdatePlayerPosition(Player* player) {
    int h = WINDOW_HEIGHT;
    int w = WINDOW_WIDTH;
    const Uint8* keyboard_state_array = SDL_GetKeyboardState(NULL);
    if (!keyboard_state_array[player->down] && keyboard_state_array[player->up]) {
        if (player->y - player->size > 0 )
        player->y--;
    }    
    if (keyboard_state_array[player->down] && !keyboard_state_array[player->up]) {
        if (player->y + player->size < h)
        player->y++;
    }
    if (!keyboard_state_array[player->left] && keyboard_state_array[player->right]) {
        if (player->x + player->size < w)
        player->x++;
    }    
    if (keyboard_state_array[player->left] && !keyboard_state_array[player->right]) {
        if (player->x - player->size > 0)
        player->x--;
    }
}

void DrawCircle(int radius, int x, int y, SDL_Renderer *renderer) {
    for (float i = 0.00f; i < 360.00f; i += 0.01f) {
        float angle = i * M_PI / 180;
        SDL_RenderDrawPoint(renderer, radius * sin(angle) + x, radius * cos(angle) + y);
    }
}
