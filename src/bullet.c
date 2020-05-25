#include <stdlib.h>
#include <stdio.h>

#include "bullet.h"
#include "utils.h"


void UpdateBullet(BulletData* bullet) {
    if ((bullet->orientation & ORIENTATION_UP) != 0) 
        bullet->y-= BULLET_SPEED;
    if ((bullet->orientation & ORIENTATION_DOWN) != 0) 
        bullet->y+= BULLET_SPEED;
    if ((bullet->orientation & ORIENTATION_LEFT) != 0) 
        bullet->x-= BULLET_SPEED;
    if ((bullet->orientation & ORIENTATION_RIGHT) != 0) 
        bullet->x+= BULLET_SPEED;
}


