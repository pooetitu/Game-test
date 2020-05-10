#ifndef PLAYER_HEADER
#define PLAYER_HEADER
#include <stdlib.h>
#include <stdio.h>

#include <SDL.h>

typedef struct PlayerData PlayerData;

struct PlayerData {
    int x;
    int y;
    int size;
    float speed;
    Uint8 r;
    Uint8 g;
    Uint8 b;
    SDL_Scancode up;
    SDL_Scancode down;
    SDL_Scancode left;
    SDL_Scancode right;
};
void UpdatePlayer(PlayerData* player, SDL_Renderer* renderer);
void UpdatePlayerPosition(PlayerData* player);

#endif 