#ifndef MAIN_HEADER
#define MAIN_HEADER

#include <stdlib.h>
#include <stdio.h>

#include <SDL.h>
#include "player.h"


void UpdatePlayer(PlayerData* player, SDL_Renderer* renderer);
void UpdatePlayerPosition(PlayerData* player);
void DrawCircle(int radius, int x, int y, SDL_Renderer *renderer);
int main(int argv, char* argc[]);

#endif