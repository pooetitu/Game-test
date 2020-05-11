#ifndef PLAYER_HEADER
#define PLAYER_HEADER

#include <stdlib.h>
#include <stdio.h>

#include <SDL.h>
#include "utils.h"
#include "bullet.h"

typedef struct PlayerData PlayerData;

struct PlayerData {
    int x;
    int y;
    int size;
    int speed;
    int orientation;
    Uint8 r;
    Uint8 g;
    Uint8 b;
    SDL_Scancode shoot;
    SDL_Scancode up;
    SDL_Scancode down;
    SDL_Scancode left;
    SDL_Scancode right;
    BulletData* bullet;
};

void UpdatePlayer(PlayerData* player, SDL_Renderer* renderer);
void UpdatePlayerPosition(PlayerData* player);
void Shoot(PlayerData* player,SDL_Renderer* renderer);
void InitBullet(PlayerData* player, BulletData* bullet);
void DeleteBullet(BulletData* bullet);
#endif 