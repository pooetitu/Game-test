#ifndef CLIENT_HEADER
#define CLIENT_HEADER

#include <stdlib.h>
#include <stdio.h>

#include <SDL.h>
#include "player.h"

#define WINDOW_HEIGHT 600;
#define WINDOW_WIDTH 800;

int ClientInit(SDL_Renderer** renderer, SDL_Window** window);
void ClientRun(SDL_Renderer* renderer, SDL_Window* window);

#endif