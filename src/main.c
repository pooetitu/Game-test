#include <stdlib.h>
#include <stdio.h>

#include <SDL.h>

#include "main.h"
#include "client.h"

int main(int argv, char* argc[]) {
    SDL_Renderer* renderer = NULL;
    SDL_Window* window = NULL;
    if (ClientInit(&renderer, &window) == 0) 
    ClientRun(renderer, window);
    else
        return 1;

    return 0;
}

void DrawCircle(int radius, int x, int y, SDL_Renderer *renderer) {
    for (float i = 0.00f; i < 360.00f; i += 0.01f) {
        float angle = i * M_PI / 180;
        SDL_RenderDrawPoint(renderer, radius * sin(angle) + x, radius * cos(angle) + y);
    }
}
