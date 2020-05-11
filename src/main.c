#include <stdlib.h>
#include <stdio.h>

#include "main.h"
#include "client.h"

int main(int argv, char* argc[]) {
    SDL_Renderer* renderer = NULL;
    SDL_Window* window = NULL;
    if (ClientInit(&renderer, &window) != 0) 
        return 1;
    ClientRun(renderer, window);
    return 0;
}

