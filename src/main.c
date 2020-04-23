#include <stdlib.h>
#include <stdio.h>

#include <SDL.h>


int main(int argv, char* argc[]) {
    
    if (SDL_Init(SDL_INIT_VIDEO))
    {
        printf("SDL initialisation error %s", SDL_GetError());
        return EXIT_FAILURE;
    }
    
    SDL_Window* window = NULL;
    window = SDL_CreateWindow("Game screen", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_RESIZABLE);
    if (window == NULL)
    {
        printf("Window initialisation error  %s", SDL_GetError());
        return EXIT_FAILURE;
    }
    
    SDL_Delay(3000);
	
    return 0;
}


