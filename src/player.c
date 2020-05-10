#include <stdlib.h>
#include <stdio.h>

#include <SDL.h>

#include "player.h"
#include "client.h"

void UpdatePlayer(PlayerData* player, SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, player->r, player->g, player->b, SDL_ALPHA_OPAQUE);
    DrawCircle(player->size, player->x, player->y, renderer);
    UpdatePlayerPosition(player);
}

void UpdatePlayerPosition(PlayerData* player) {
    int h = WINDOW_HEIGHT;
    int w = WINDOW_WIDTH;
    const Uint8* keyboard_state_array = SDL_GetKeyboardState(NULL);
    if (!keyboard_state_array[player->down] && keyboard_state_array[player->up]) {
        if (player->y - player->size > 0)
            player->y-= player->speed;
    }
    if (keyboard_state_array[player->down] && !keyboard_state_array[player->up]) {
        if (player->y + player->size < h)
            player->y+= player->speed;
    }
    if (!keyboard_state_array[player->left] && keyboard_state_array[player->right]) {
        if (player->x + player->size < w)
            player->x+= player->speed;
    }
    if (keyboard_state_array[player->left] && !keyboard_state_array[player->right]) {
        if (player->x - player->size > 0)
            player->x-= player->speed;
    }
}
