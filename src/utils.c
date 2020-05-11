#include <stdlib.h>
#include <stdio.h>

#include <SDL.h>

#include "utils.h"

void DrawCircle(int radius, int x, int y, SDL_Renderer* renderer) {
    for (float i = 0.0f; i < 360.0f; i += 0.1f) {
        float angle = i * M_PI / 180;
        SDL_RenderDrawPoint(renderer, radius * sin(angle) + x, radius * cos(angle) + y);
    }
}