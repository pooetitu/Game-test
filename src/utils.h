#ifndef UTILS_HEADER
#define UTILS_HEADER
#include <stdlib.h>
#include <stdio.h>

#include <SDL.h>

#define ORIENTATION_UP 1
#define ORIENTATION_DOWN 2
#define ORIENTATION_LEFT 4
#define ORIENTATION_RIGHT 8

void DrawCircle(int radius, int x, int y, SDL_Renderer* renderer);

#endif