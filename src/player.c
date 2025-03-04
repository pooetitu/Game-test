#include <stdlib.h>
#include <stdio.h>

#include <SDL.h>

#include "player.h"
#include "utils.h"
#include "client.h"
#include "bullet.h"

void UpdatePlayer(PlayerData* player, SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, player->r, player->g, player->b, SDL_ALPHA_OPAQUE);
    DrawCircle(player->size, player->x, player->y, renderer);
    UpdatePlayerPosition(player);
    Shoot(player,renderer);

    if (player->bullet != NULL) {
        if ((player->bullet->y >= 600 || player->bullet->y < 0) || (player->bullet->x >= 800 || player->bullet->x < 0)) {
            BulletData* bulletOld = player->bullet->old;
            free(player->bullet);
            player->bullet = bulletOld;
        }
    }


    BulletData* bullet = player->bullet;
    int i = 0;



    while (bullet != NULL) {
        i++;
        UpdateBullet(bullet);
        SDL_Rect rect;
        rect.x = bullet->x;
        rect.y = bullet->y;
        rect.w = 3;
        rect.h = 3;
        SDL_RenderFillRect(renderer, &rect);
        DeleteBullet(bullet);
        bullet = bullet->old;
    }
    printf("%d\n", i);
}

void UpdatePlayerPosition(PlayerData* player) {
    int h = WINDOW_HEIGHT;
    int w = WINDOW_WIDTH;
    const Uint8* keyboard_state_array = SDL_GetKeyboardState(NULL);
    if (!keyboard_state_array[player->down] && keyboard_state_array[player->up]) {
        if (player->y - player->size > 0) {
            player->y -= player->speed;
        }
            player->orientation = ORIENTATION_UP;
            if ((player->orientation & ORIENTATION_DOWN) != 0)
                player->orientation -= ORIENTATION_DOWN;
    }
    if (keyboard_state_array[player->down] && !keyboard_state_array[player->up]) {
        if (player->y + player->size < h) {
            player->y += player->speed;
        }
            player->orientation = ORIENTATION_DOWN;
            if ((player->orientation & ORIENTATION_UP) != 0)
                player->orientation -= ORIENTATION_UP;
    }
    if (!keyboard_state_array[player->left] && keyboard_state_array[player->right]) {
        if (player->x + player->size < w){
            player->x += player->speed;
        }
            player->orientation = ORIENTATION_RIGHT;
            if ((player->orientation & ORIENTATION_LEFT) != 0)
                player->orientation -= ORIENTATION_LEFT;
    }
    if (keyboard_state_array[player->left] && !keyboard_state_array[player->right]) {
        if (player->x - player->size > 0){
            player->x -= player->speed;
        }
            player->orientation = ORIENTATION_LEFT;
            if ((player->orientation & ORIENTATION_RIGHT) != 0)
                player->orientation -= ORIENTATION_RIGHT;
    }
}

void Shoot(PlayerData* player,SDL_Renderer* renderer) {
    if (SDL_GetKeyboardState(NULL)[player->shoot]) {
        BulletData* bullet = malloc(sizeof(BulletData));
        if (bullet) {
            InitBullet(player, bullet);
        }
    }
}

void InitBullet(PlayerData* player, BulletData* bullet) {
    bullet->old = player->bullet;
    player->bullet = bullet;
    bullet->x = player->x;
    bullet->y = player->y;
    bullet->orientation = player->orientation;
}

void DeleteBullet(BulletData* bullet) {
    int w=WINDOW_WIDTH;
    int h=WINDOW_HEIGHT;
    if (bullet->old != NULL) {
        if ((bullet->old->y >= h || bullet->old->y < 0) || (bullet->old->x >= w || bullet->old->x < 0)) {
            BulletData* bulletOld = bullet->old->old;
            free(bullet->old);
            bullet-> old = bulletOld;
        }
    }
}

void BulletCollision(PlayerData* player,BulletData** bullet) {
    while (*bullet != NULL) {
            printf("%d\n", &(*bullet));
        if ((*bullet)->y < player->y + player->size && (*bullet) ->y > player->y - player->size
            && (*bullet)-> x < player->x + player->size && (*bullet)-> x > player->x - player->size ) {
            printf("rip");
            player->size -= 1;
            BulletData* bulletOld = (*bullet)->old;
            free((*bullet));
            (*bullet) = bulletOld;
        }
        else {
            bullet = &(*bullet)->old;
        }
    }
}