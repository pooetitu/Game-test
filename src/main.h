#include <stdlib.h>
#include <stdio.h>

#include <SDL.h>

#define WINDOW_HEIGHT 600;
#define WINDOW_WIDTH 800;

typedef struct Player Player;

void UpdatePlayer(Player* player, SDL_Renderer* renderer);
void UpdatePlayerPosition(Player* player);
void DrawCircle(int radius, int x, int y, SDL_Renderer *renderer);
int main(int argv, char* argc[]);