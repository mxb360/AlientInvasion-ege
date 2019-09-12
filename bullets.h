#ifndef _BULLETS_H_
#define _BULLETS_H_

#include "plane_war.h"

#include "plane.h"
#include "game_stats.h"

typedef Rect Bullet;
typedef struct {
    PIMAGE image;
    Bullet *bullets[BULLET_ALLOWED];
    int    bullet_count;
    int    speed;
} Bullets;

void bullets_init(Bullets *bullets);
void bullets_create_bullet(Plane *plane);
void bullets_update(GameStats *stats);
void bullets_draw(void);
void bullets_destroy(void);
void bullets_clear(void);

#endif
