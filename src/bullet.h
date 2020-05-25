#ifndef BULLET_HEADER
#define BULLET_HEADER
#define BULLET_SPEED 8;
#include <stdlib.h>
#include <stdio.h>


#include "utils.h"

typedef struct BulletData BulletData;
struct BulletData {
	BulletData* old;
	int x;
	int y;
	int orientation;
}; 

void UpdateBullet(BulletData* bullet);

#endif